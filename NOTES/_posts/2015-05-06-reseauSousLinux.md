---
title: Connaitre son réseau sous Linux
layout: post
date: 2015-05-06  00:38
tags: [linux, bash]
category: notes
---

# Connaitre son réseau sous Linux

Pour connaître l'IP, le broadcast, le masque et l'adresse MAC

    $ ifconfig 
    eth0      Link encap:Ethernet  HWaddr 8c:89:a5:05:d7:ca  
              inet adr:192.168.1.8  Bcast:192.168.1.255  Masque:255.255.255.0
              adr inet6: fe80::8e89:a5ff:fe05:d7ca/64 Scope:Lien


Pour connaitre l'adresse du serveur DHCP 

    $ sudo grep -R "DHCPOFFER" /var/log/
    /var/log/syslog.1:May  4 22:30:10 msi dhclient: DHCPOFFER of 192.168.1.10 from 192.168.1.254

Pour connaitre la passerelle

    $ route -n
    Table de routage IP du noyau
    Destination     Passerelle      Genmask         Indic Metric Ref    Use Iface
    0.0.0.0         192.168.1.254   0.0.0.0         UG    0      0        0 eth0
    192.168.1.0     0.0.0.0         255.255.255.0   U     1      0        0 eth0



