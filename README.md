# MiniProject C++ 

## Files content:
characterClass.h contains all the prototypes.  
ProjectClasses.cpp contains all the classes declarations.  
main.cpp shows how to use the classes and output a text character sheet.  

## Logic 
The character creation is handled by a specific class : CharacterCreation.  
It reflects page 88 of the rules book as well as the futur GUI. 
The character generation is made step by step (from 0 to 5). Each step will be a View of the upcoming GUI.  
For example for the step 0, the GUI will ask for the name, player, generation, sir, etc. By clicking next, those informations
will be fed to the character creation method "stepZero". 
At the end the CharacterCreation class will return the Character object.  
The CharacterCreation class allows to pass only one object between views, and free the Character object of initialization method 
that will not be usefull if we extend the program (meaning more than just the creation step but also updating the character sheet while playing).
\

Safeguards, such as checking that the user don't choose more than 3 discplines will be implemented in the GUI rather 
than in the characters classes.

Each object (clan, disciplines, nature, etc) is created and given to the characterCreation class that will add it to the 
character object.  

The classes presented here don't handle all the informations, for two reasons : 
- Without parsing it's difficult to see for the moment how to organise them, what type they will be or the method needed to interact with them. 
- The classes presented here are enough to generate the character sheet, the additional informations will probably be parsed in another way and 
just invocated by the GUI if the user click on a "more detail" button for example. However this step may be not needed as the page of the rule book 
holding the informations may be shown to stay consistent with the final output, rather than displaying the additionnal information directly in the GUI.   



## Output of main.cpp
```
  @@@@@@@@@@@ Fiche Personnage @@@@@@@@@@@@@
  #############BACKGROUND#############
  My name is Hugdrula
  I'm the player : Hugo
  We're playing the chronicle :Chroniques de test
  My concept is :student
  I'm a vampire of the Fourth generation
  My Sire was Sr. Tempel
  Let me tell you about my clan :
  My clan's name is DLAD
  Its The Best of the best.
  I say i'm a Bon Vivant
  But truth is, i'm really more a Capitalist
  ####################################
  ########## Attributes #######
  #Physical 
  Strength : 3
  Dexterity : 3
  Stamina : 1
  #Social
  Charisma : 2
  Manipulation : 2
  Appearance : 1
  #Mental 
  Perception : 1
  Intelligence : 1
  Wits : 1
  ########## Abilities #######
  #Talents :
  Alertness 2
  Awareness 2
  Leadership 2
  #Skills :
  Etiquette 0
  Firearms 2
  Melee 2
  #Knowledges :
  Academics 2
  Computer 2
  Finance 0
  ########## Advantages #######
  #Disciplines
  Animalism : 1
  Fortitude : 3
  Thaumaturgy : 4
  #Backgrounds
  Mentor : 2
  #Virtues
  Conscience : 4
  Instinct : 4
  Courage : 2
  ########## Etc #######
  Blood Pool : 50/50
  Humanity points : 6
  Willpower points : 2
```