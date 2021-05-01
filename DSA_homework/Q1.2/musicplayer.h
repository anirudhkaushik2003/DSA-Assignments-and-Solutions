
/*NOTE: Due to the playlist being arranged in the form of linked lists, select a particular track takes linear time */

#ifndef __MUSIC_PLAYER_H__
#define __MUSIC_PLAYER_H__

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct tracks track;
typedef struct master_controls control;

int current_queue_number = 1; //stores the queue number of the latest track, first_track gets value 1

struct tracks //has variables that store names of songs and their corresponding number on the queue
{
    int queue_number;          //stores position of song on the queue and decrements it by one each type the current song ends to move its position upwards
    char name_of_song[20 + 1]; //stores the name of the song in the form of a string
    track *next;               //points to next song in the list;
};

track *first_track = NULL; // A global variable that is the head of the playlist and is the first track
track *pointer_to_first_node_of_new_stack_created_by_shuffle_track;

struct master_controls //contains commands for controls like play, pause, next song,etc.
{

    bool status;      //TRUE if song is playing(i.e play mode) and FALSE if song is paused(i.e pause mode)
    int volume_level; //to manually determine the volume of cuurent track being played

    bool next;     //if TRUE plays next track, if FALSE stays on current track (FALSE by default, can be changed with user conrols)
    bool previous; //if TRUE plays previous track, if FALSE stays on current track (FALSE by default, can be changed with user conrols)
    bool loop;     // if TRUE plays current track on loop, if FALSE plays next song after current track ends (FALSE by default, can be changed with user conrols)
    bool shuffle;  //if TRUE shuffles all the queued songs (does nothing if there is only one song), if FALSE plays tracks in the order they were queued by the user (FALSE by default, can be changed with user conrols)
};

void create_first_node(track *first_track) //the first track is sent to this function
{
    first_track->next = NULL; // initializes the head of the playlist, later the next pointer is made to point to track with ques number 2
}

void create_playlist(track *track_num); //creates a playlist in the form of a linked list, takes a (struct tracks) type variable as argument and makes it the head(first element) of the linked list
//corresponding elements are assigned second, third etc place respectively by making track_num.next point to them and the last node points to NULL

void add_track(track *track_num)
{

    scanf("%s", track_num->name_of_song); //stores name of song being queueued

    track_num->queue_number = current_queue_number; //assigns the latest track a queue number
    current_queue_number++;                         //increments queue number so that next track gets the next value

    if (track_num->queue_number == 1)
    {
        *first_track = *track_num;
        create_first_node(first_track); //sends first track to create_first_node(), second track onwards gets sent to create_playlist()
    }
    else
    {
        create_playlist(track_num); //second track onwards, tracks are sent here

        /*this takes a track number as input and sends it to create_playlist, the difference between add-track() and create_playlist() is that create_playlist() mainly handles the 
        linked list making part whereas add_playlist() just sends a track to create_playlist(), having two different functions increases readibility*/
    }
}

track *current_track(track *first_track, int current_track_number) //returns the current track
{
    /*searches the linked list to find the current track with the help of the current_track_number*/
    track *p;

    for (p = first_track; p != NULL; p = p->next)
    {
        if (p->queue_number == current_track_number)
        {
            return p; // sends the current track as output
        }
    }
}

void play_song();                           //plays current track
void pause_song();                          //pauses current track
void play_next_track();                     //plays next track
void play_prev_track();                     //pauses next track
void volume_level_controller(control user1) //takes a master_controls type struct variable and allows you to enter a an integer to determine volume level
{
    int volume;
    volume = user1.volume_level; //sets volume level to what the user decides
    //input for volume level will be taken through master controls provided through main.c
}

track *shuffle_tracks(track *first_track); //shuffles the tracks by creating another linked list and making the old list's next pointers point to the list elements in a random order and the new list is used as a reference o restore the order when shuffle is set to false
//returns pointer to first node of new linked list

void deshuffle(track *first_node_of_new_list); //restores the previous order using pointer returned by shuffle_tracks()

void loop_current_track(track *track_num)
{
    track_num->next = track_num; // makes the next pointer in a track point to itself to loop
    //loop is removed by not_loop()
}

void not_loop(track *track_num)
{
    track *p;

    for (p = first_track; p != NULL; p = p->next)
    {
        if (p->queue_number == track_num->queue_number)
        {
            track_num->next = p->next; //removes the loop by making current track's next pointer point to the next track
        }
    }
}

void status_checker(control user1, int current_track_number) //helps implement user controls over the flow of music, track selection etc.
{
    /*there will be a way in main.c for the user to manually update the master controls, this function is then called with struct master_controls type variable as a parameter */
    //main.c is part of the user interface and it sends the update user controls and current track number to status_checker()

    if (user1.status == true)
    {
        play_song();
    }
    else
    {
        pause_song();
    }
    if (user1.next == true)
    {
        play_next_track(); //plays next track
        //else current track continues to play
    }
    if (user1.previous == true)
    {
        play_prev_track(); //plays previous track
        //else current track continues to play
    }
    if (user1.loop == true)
    {
        loop_current_track(current_track(first_track, current_track_number)); //loops current track by calling current track and sending its return value to loop_current_track()
    }
    else
    {
        not_loop(current_track(first_track, current_track_number)); // removes the loop by calling current track and sending its return value to not_loop()
    }
    if (user1.shuffle == true)
    {
        pointer_to_first_node_of_new_stack_created_by_shuffle_track = shuffle_tracks(first_track);
    }
    else
    {
        deshuffle(pointer_to_first_node_of_new_stack_created_by_shuffle_track);
    }
}
//SOME EXTRA FUNCTIONS WITHOUT IMPLEMENTATION

void find_lyrics(); //finds lyrics for the current track by providing a google link
void find_music_video(); //finds music video for the current track by providing a google link
void find_artist_info(); //finds info about the artist by googling the song and provides link

#endif
