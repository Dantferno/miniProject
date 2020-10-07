# MiniProject C++ 

## Files content:
characterClass.h contains all the prototypes.  
ProjectClasses.cpp contains all the classes declarations.  
main.cpp shows how to use the classes and output a text character sheet.  

## Logic 
The character creation is handled by a specific class : CharacterCreation.  
It reflects page 88 of the rules book as well as the futur GUI. 
The character generation is made step by step (from 0 to 5). Each step will be a view of the upcoming GUI.  
For example for the step 0, the GUI will ask for the name, player, generation, sir, etc. By clicking next, those informations
will be fed to the character creation method "stepZero". 


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