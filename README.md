# block_o_automata

My* version of a automata game

## the origin of the idea

So long time ago I 've seen a video of a guy writing game for some king of game jam, anyway so he did an automata game
that player sets up blocks, and then he presses start and the game plays itself

kinda cool

the guy made it in c# using unity I'll try to find the original and link it below

## my approach

I'll try to recreate the idea on my own

<ol>
<li> create plane class containing array of cells
<li> create cell class

- un movable block cell #
- movable block cell
- kill cell
- create/spawn cell
- move forward cell
- goal cell
- cells that can be accessed by player
- calls that can not
- turn cell

<li>console version <- default one  
<li>sdl version 

- animations ehhhhhh....

  well I wanted to avoid this step, but I guess there's no way i will
- nice blocks png's

<li> user input handling 
<li> level editor 
<li>opening / end screen

<li> bloom effect must have 
</ol>

# Idea bard

### cells

tp teleport cell

# TODO

there's list of must-have elements:
<ol>
<li><del> wait for input dome tim, than close window and do something else</del>
<li> <del>we need to have correct event flow, if we close window we must back to where we were before opening it</del>
<li> <del>i still didn't finish throphys</del>
<li> <del>below the level and controls we need to display what is user doing<br>
if he's on quit button we show exit itd...</del>
<li> <del>in level_play we are still able to put blocks on locked places</del>
<li> <del>we need to make delete block usable</del>>
<li> <del>level_pick uses old system</del>
<li> display witch iteration it currently is
<li><del> display max piece cost <- figure out what that means</del>
<li> engine does not work in a right way,
we have some bugs there  


</ol>

# BUGS

## Edit

- message system is not implemented

## Level_info


## Engine 
- unmovable block can be moved by crushing into it with move block

