--
title: RaspberryPi : Compteur avec un afficheur 7 segments
date: 2015-05-15 17:40
tags: Raspberry, Python
permalink: afficheur-7segments-sous-raspberry-pi
category: Raspberry
--


# Schémas de branchement

## branchements du 8 bit-shift register 74HC595N
        _____
     Q1 -1-|  7  |-16- Vcc      --> to 5V
     Q2 -2-|  4  |-15- Q0
     Q3 -3-|  H  |-14- Data     --> to GPIO 18
     Q4 -4-|  C  |-13- Enable   --> to ground
     Q5 -5-|  5  |-12- Latch    --> to GPIO 24
     Q6 -6-|  9  |-11- Clock    --> to GPIO 23
     Q7 -7-|  5  |-10- Reset    --> to 5V
    GND -8-|__N__|--9- Overflow


## Branchements de l'afficheur 7 segments

    Q6 Q5 G Q0 Q1
     g  f   a  b
     |  | | |  |
         -a-
       f|   |b
         -g-
       e|   |c
         -d-   .h
     |  | | |  |
     e  d   c  h
    Q4 Q3 G Q2 Q7

# Avec Python

Quelques outils

    :::bash
    $ sudo apt-get install python-setuptools
    $ cd PiShiftPy-master/
    $ python setup.py build
    $ sudo python setup.py install

Puis un programme simple qui affiche les 10 chiffres en boucle
    
    :::python
    #!/usr/bin/env python

    import PiShiftPy as shift
    import time
    import RPi.GPIO as GPIO
    
    tab = [0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F]
    RUNNING = True
    print("de 0 a 9 sur 7 segments : CTRL+C pour quitter")
    
    shift.init()
    try:
      while RUNNING:
        for i in tab:
          shift.write(i)
          time.sleep(1)
    
    except KeyboardInterrupt:
      RUNNING = False
      print("\nOn eteint la lumiere.")
    
    finally:
      # Arrete et nettoie les broches pour les liberer
      # en vue d'une prochaine utilisation.
      shift.init()
      GPIO.cleanup()

