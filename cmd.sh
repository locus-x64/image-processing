touch invert.pgm
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm invert invert
touch verticalFlip.pgm
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/dragon.pgm verticalFlip verticalFlip
touch horizontalFlip.pgm
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/dragon.pgm horizontalFlip horizontalFlip
touch rotate.pgm
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm rotate rotate

touch 25.pgm 50.pgm 75.pgm 100.pgm 125.pgm 150.pgm 175.pgm 200.pgm  
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 25.pgm scale 0.25
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 50.pgm scale 0.5
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 75.pgm scale 0.75
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 100.pgm scale 1
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 125.pgm scale 1.25
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 150.pgm scale 1.50
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 175.pgm scale 1.75
g++ SimpleImage.cpp image_processing.cpp -o go && ./go images/mona_lisa.pgm 200.pgm scale 0.2
