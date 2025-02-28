# 23 Dover

Game Name - a catchy, descriptive name for your game.
23 Dover
Team - the names and email addresses of the team members, including a team name.
Cole Bennett - nmbennett@wpi.edu
Joe Pisano - jjpisano@wpi.edu 
Genre - a brief, one sentence/phrase of the game genre.
Tower defense
Game Description - a short, one paragraph description of your game.
Mice are invading 23 Dover St. You MUST defend it. Utilize a variety of traps to neutralize and slow down the invaders. Never before seen immersive gameplay. Created from first person experiences, based on a true story.
Technical Features - a list of the specific, significant technical features that your game will include.
Traps: (Cost)
Mouse traps
Glue traps
Mouse repellent
Traps cost points
Mice:
Pathing, speed (slowdown, blowback), death, points
Artistic Assets - a list of the significant artistic assets that that your game will include (both audio and sprites). Sizes and frames of animations you will create should be estimated.
Mice sprites
~o:>
<:8O~
~O8:>
      ___
~=(___)8:> - White
Trap sprites:
Mouse trap - Red?
Glue trap - Yellow
Mouse repellent - Green

Implementation Plan - A short description of how you plan to implement the technical features of your game. While the entire game should be original, if you are using code (or artwork) from elsewhere this should be clearly indicated and attributed.
We will draw a base scene with a set path along it. The mice will be programmed to follow this path. Then it is up to the player where to place their traps. Traps will interact with the path sections around them based on each trap’s specific range. This will usually result in the traps placing something onto the path to interrupt the mice’s path. This will be done with a core Trap class that will then be used to derive all the remaining traps and their specific created obstacles. The player will select things with their computer mouse and then choose the location to place them on the map. For the proper “game” portion there will be a few globally tracked variables: Money, Health, and Wave. Money will be earned upon neutralizing mice, Health will be lost upon mice reaching the end, and Wave will control the content of the mice within the given Wave.
Distribution of Work - broadly, what team member is responsible for what aspects of the project. Joint responsibility can be indicated, if appropriate.


Schedule - milestones and when they will be met for your game development. While the major milestones (plan, alpha, final, presentation) are fixed, smaller milestones should be specified as appropriate for your project.
Plan - Thursday, February 27th (11:59pm)
Alpha - Monday, March 3rd (11:59pm)
Final playable - Wednesday, March 5th (11:59pm)
Promotional material - Friday, March 7th (2:59pm)
Presentation - Friday, March 7th (in class)
