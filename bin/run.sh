g++ -g -c ../src/main.cpp ../src/core/*.cpp ../src/rules/*.cpp ../src/graphics/*.cpp &&
g++ -g ./*.o -o game -lsfml-graphics -lsfml-window -lsfml-system &&
rm ./*.o &&
./game
