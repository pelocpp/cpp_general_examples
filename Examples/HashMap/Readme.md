# Text zu Hash Map

## Schreiben eines Standardbibliothekscontainers

Der C++-Standard enth�lt eine Liste von Anforderungen, die jeder Container erf�llen muss,
um sich als Standardbibliothekscontainer zu qualifizieren.

Wenn au�erdem die Anforderung besteht, dass der Container sich sequentiell (wie ein std::vector),
geordnet assoziativ (wie std::map) oder
ungeordnet assoziativ (wie eine std::unordered_map) verh�lt,
muss er erg�nzenden Anforderungen entsprechen.

In dieser Fallstudie verfolgen wir den Ansatz zur Entwicklung einer Hash-Tabelle verwendet.

## Basics einer Hash Tabelle

Eine Hash-Tabelle hasht jedes Element oder ordnet es einem bestimmten Bucket zu.

Solange die Anzahl der gespeicherten Elemente nicht wesentlich gr��er ist als die Anzahl der Buckets

und die Hash-Funktion die Elemente gleichm��ig auf die Buckets verteilt,

werden die Einf�ge-, L�sch- und Suchvorg�nge alle in konstanter Zeit ausgef�hrt.


In dieser Fallstudie wird eine einfache, aber voll funktionsf�hige hash_map implementiert.

Im Container werden hash_map Schl�ssel/Wert-Paare abgelegt.

Tats�chlich sind die von ihr bereitgestellten Operationen nahezu identisch mit denen der Karte,

weisen jedoch unterschiedliche Leistungsmerkmale auf.


Diese hash_map-Implementierung verwendet verkettetes Hashing (auch offenes Hashing genannt).

## The Hash Function

