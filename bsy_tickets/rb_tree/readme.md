Rot Schwarz Baum

Der Rot Schwarz Baum ist ein selbstbalancierter binärer Suchbaum.
Jedem Knoten ist eine Farbe (rot oder schwarz) zugewiesen. Regeln bestimmen
wie diese Farben angeordnet sein müssen. (zB haben rote Knoten keine roten Kinder).
Hierdurch wird festgestellt, dass der Baum eine gewisse Balance hält.

Nach dem Einfügen und löschen von Knoten werden Algorythmen angewendet, um die Erhaltung
der Regeln zu überprüfen. Bei Abweichungen werden die jeweiligen Knoten und Rotationen
umgefärbt.

NIL-Knoten

ein NIL-Knoten ist ein Blatt, das keinen wert enthält. NIL-Knoten werden im späteren Verlauf
für die Algorythmen relevant, um zB Farben von Onkel und Geschwister knoten zu bestimmen.
Sie können als NULL referenzen dargestellt werden. (Sie hängen an den unteren Knoten)



Eigenschaften:
1. Jeder Knoten ist entweder Rot oder Schwarz
2. (Die Wurzel ist schwarz)
3. Alle NIL-Blätter sind schwarz
4. Ein roter Knoten darf keine roten Kinder haben
5. Alle Pfade von einem Knoten zu den darunterliegenden Blättern enthalten die gleiche Anzahl an schwarzer Knoten


Höhe des Rot-Schwarz-Baums:

Die Höhe ist die maximale Anzahl an Knoten von der Wurzel bis zu einem NIL-Blatt, die Wurzel
nicht mit einberrechnet.
(Der längste Pfad von der Wurzel zu einem Blatt ist maximal doppelt so lang wie der kürzeste Pfad von der Wurzel zu einem Blatt)
