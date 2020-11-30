# MiniProject C++ 
Video demonstration : https://youtu.be/_7-lVQCc0v8

## Files content:
characterClass.h contains all the prototypes.  
ProjectClasses.cpp contains all the classes declarations.  
DrawingPart.cpp contains drawingArea related declaration. 
GUI.h contains all the GUI related prototypes.
GUI.cpp contains all the GUI pages declarations.
GUIutils.cpp contains all the button bindings.
main.cpp launch the GUI.  


## Logic 

The character creation controls the model Character, and creates it 

The character creation is handled by a specific class : CharacterCreation.  
It reflects page 88 of the rules book as well as the GUI. 
The character generation is made step by step (from 0 to 5). Each step is a view of the GUI.  
For example, for the step 0, the GUI asks for the name, player, generation, sir, etc. By clicking "next", those informations
are fed to the character creation method "stepZero". 
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

## Progression with the GUI 

On the first page you will be asked to input your character's informations.

On the second page you wil be able to select your attributes points. 

On the third page the abilities, ont the fourth one the advantages and finally you will be prompted to add the freebies. 
Finally, the PDF is generated. 
