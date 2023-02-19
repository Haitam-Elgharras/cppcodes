set term png
set output "courbe_fusion.png"
set xlabel "Taille du tableau"
set ylabel "Temps d'exécution (microseconds)"
set title "Tri par fusion"
plot "data.txt" with lines
