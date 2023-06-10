# Text zu Hash Map

## Schreiben eines Standardbibliothekscontainers

Der C++-Standard enthält eine Liste von Anforderungen, die jeder Container erfüllen muss,
um sich als Standardbibliothekscontainer zu qualifizieren.

Wenn außerdem die Anforderung besteht, dass der Container sich sequentiell (wie ein std::vector),
geordnet assoziativ (wie std::map) oder
ungeordnet assoziativ (wie eine std::unordered_map) verhält,
muss er ergänzenden Anforderungen entsprechen.

In dieser Fallstudie verfolgen wir den Ansatz zur Entwicklung einer Hash-Tabelle verwendet.

## Basics einer Hash Tabelle

Eine Hash-Tabelle hasht jedes Element oder ordnet es einem bestimmten Bucket zu.

Solange die Anzahl der gespeicherten Elemente nicht wesentlich größer ist als die Anzahl der Buckets

und die Hash-Funktion die Elemente gleichmäßig auf die Buckets verteilt,

werden die Einfüge-, Lösch- und Suchvorgänge alle in konstanter Zeit ausgeführt.


In dieser Fallstudie wird eine einfache, aber voll funktionsfähige hash_map implementiert.

Im Container werden hash_map Schlüssel/Wert-Paare abgelegt.

Tatsächlich sind die von ihr bereitgestellten Operationen nahezu identisch mit denen der Karte,

weisen jedoch unterschiedliche Leistungsmerkmale auf.


Diese hash_map-Implementierung verwendet verkettetes Hashing (auch offenes Hashing genannt).

## The Hash Function

