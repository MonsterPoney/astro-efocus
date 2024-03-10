# E-focus
## EN
Repo for an electronic focus upgrade of a telescope.
Once installed, usage is really simple:
- The potentiometer in middle position does nothing
- Turn it left or right to adjust the focus in a direction
- The more you turn the faster the focus will move

![demo](/readme_resources/efocus-demo.gif?raw=true)

### Generalities
Project difficulty :
Basic knowledges on the usage of an arduino

To keep things clean, I will focus here on the electronic & programmation
And for the 3d printed parts, go to this [Thingiverse page](https://www.thingiverse.com/thing:<TODO: Thingiverse page>)


Parts needed: 
- Motor Driver (TB6612FNG)
- Arduino or your preferred µC with a pwm pin (I used an ATTINY85)
- 10k Ohm potentiometer
- DC motor (I used a small one 30RPM, high torque)
- 5v power supply
- Wires

### Electronic
If you choose to use a standalone µC, you can either use a perfboard or make a PCB.
Extended Gerber (RS-274X) available in this repo.
PCB dimensions are 43.5mm x 43.1mm
![pcb](/readme_resources/pcb.jpg?raw=true)

Wiring:
![wiring](/readme_resources/schem.svg?raw=true&sanitize=true)

### Programmation
Nothing too fancy here, the code is short and simple.
If you choose a potentiometer with the same value and the same power supply the code should be fine.
I highly recommand you to test the setup on a breadboard before soldering because you may need to make some adjustments according to your preferences (bigger or smaller deadzone on the potentiometer for exemple).

Comments in the code speaks for themselves
I used a library for the motor driver available [here](https://github.com/AndreaLombardo/L298N/) or via the library manager in ArduinoIDE, search for "L298N" by Andrea Lombardo:
![library](/readme_resources/library.PNG?raw=true)

To upload to an ATTINY85 I added this URL https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json in the board manager in preferences.
![settings](/readme_resources/settings.PNG?raw=true)

For reminder, you need to burn the bootloader when using a brand new µC before uploading the code.

I put STBY pin of the motor driver to be always HIGH so it's not controlled by the µC, simplier and one less source of problem even if it's not optimised. Plus it only draw a negligible current and it's not a problem with a DC motor comparred to a stepper.


### A bit of troubleshoot
- Arduino error "Device signature = 0x000000 invalid device signature" when burning bootloader
	Can be a bad wiring so the µC is not correctly recognized.
	Can be a bad configuration under Tools> Check board, port, clock, processor & programmer
	Can be a dead µC
	
- The motor turn in a direction but not in the other
	Check the wirering, it can happen if you inversed the PWMA & AIN2 pins

## FR
Projet pour une amélioration électronique du focus d'un télescope.
Une fois installé, l'utilisation est très simple :
- Le potentiomètre en position médiane ne fait rien
- Tournez-le à gauche ou à droite pour régler la mise au point dans une direction
- Plus vous tournez, plus le focus se déplacera rapidement

![demo](/readme_resources/efocus-demo.gif?raw=true)

### Généralités
Difficulté du projet :
Connaissances de base sur l'utilisation d'un arduino

Pour garder les choses propres, je vais me concentrer ici sur l'électronique et la programmation.
Pour les pièces imprimées en 3D, rendez-vous sur cette [page Thingiverse](https://www.thingiverse.com/thing:<TODO : page Thingiverse>)


Pièces nécessaires :
- Driver moteur (TB6612FNG)
- Arduino ou votre µC préféré avec une broche pwm (j'ai utilisé un ATTINY85)
- Potentiomètre 10k Ohms
- Moteur DC (j'en ai utilisé un petit 30RPM, couple élevé)
- Alimentation 5V
- Des fils

### Électronique
Si vous choisissez d'utiliser un µC autonome, vous pouvez soit utiliser une perfboard, soit faire un PCB.
Gerber (RS-274X) disponible.
Les dimensions du PCB sont de 43,5 mm x 43,1 mm
![pcb](/readme_resources/pcb.jpg?raw=true)

Câblage :
![wiring](/readme_resources/schem.svg?raw=true&sanitize=true)

### Programmation
Rien de bien compliqué ici, le code est simple.
Si vous choisissez un potentiomètre avec la même valeur et la même alimentation, le code devrait convenir.
Je vous recommande fortement de tester le montage sur une breadboard avant de souder car vous devrez peut-être faire quelques réglages selon vos préférences (zone morte plus grande ou plus petite sur le potentiomètre par exemple).

Les commentaires dans le code parlent d'eux-mêmes
J'ai utilisé une bibliothèque pour le driver de moteur disponible [ici](https://github.com/AndreaLombardo/L298N/) ou via le gestionnaire de bibliothèque dans ArduinoIDE, recherchez "L298N" par Andrea Lombardo :
![library](/readme_resources/library.PNG?raw=true)

Pour télécharger sur un ATTINY85, j'ai ajouté cette URL https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json dans le gestionnaire de cartes dans les préférences.
![settings](/readme_resources/settings.PNG?raw=true)

Pour rappel, vous devez graver le bootloader lorsque vous utilisez un tout nouveau µC avant de téléverser le code.

J'ai mis la broche STBY du driver du moteur pour être toujours HIGH pour qu'elle ne soit pas contrôlée par le µC, c'est plus simple et c'est une source de problème en moins même si ce n'est pas optimisée. De plus, il ne consomme qu'un courant négligeable et ce n'est pas un problème avec un moteur à courant continu par rapport à un moteur pas à pas.


### Un peu de dépannage
- Erreur Arduino "Device signature = 0x000000 invalid device signature" lors de la gravure du bootloader
	Il peut s'agir d'un mauvais câblage et le µC n'est donc pas correctement reconnu.
	Peut être une mauvaise configuration sous Outils> Vérifier la carte, le port, l'horloge, le processeur et le programmateur
	Peut être un µC mort

- Le moteur tourne dans un sens mais pas dans l'autre
	Vérifiez le câblage, cela peut arriver si vous avez inversé les broches PWMA et AIN2
