# MiniProject C++ 

## Files content:
characterClass.h contains all the prototypes.  
ProjectClasses.cpp contains all the classes declarations.  
DrawingPart.cpp contains drawingArea related declaration. 
GUI.h contains all the GUI related prototypes.
GUI.cpp contains all the GUI pages declarations.
GUIutils.cpp contains all the button bindings.
main.cpp launch the GUI.  


## Logic 
The character creation is handled by a specific class : CharacterCreation.  
It reflects page 88 of the rules book as well as the GUI. 
The character generation is made step by step (from 0 to 5). Each stepis a view of the GUI.  
For example, for the step 0, the GUI will ask for the name, player, generation, sir, etc. By clicking "next", those informations
will be fed to the character creation method "stepZero". 
At the end the CharacterCreation class returns the Character object.  

\

Safeguards, such as checking that the user don't choose more than 3 discplines are implemented in the GUI

Each object (clan, disciplines, nature, etc) is created and given to the characterCreation class that will add it to the 
character object.  

## Usage 

Compilation using Cmake (minimum version 2.8) , just run :
```
    cmake CmakeLists.txt
    make 
    ./miniProject
```
