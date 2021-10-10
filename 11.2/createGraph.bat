@echo off

"../Release/Source.exe"
"C:\Program Files\Graphviz\bin\dot.exe" -Tpng graph.dot -o graphImage.png
TIMEOUT /T 1
start graphImage.png