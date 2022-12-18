CC=gcc
CFLAGS=
writeName=write
displayName=show
imageName=testi

make: displayImage.c writeImage.c
	$(CC) $(CFLAGS) -o $(displayName) displayImage.c
	$(CC) $(CFLAGS) -o $(writeName) writeImage.c

write: writeImage.c
	$(CC) $(CFLAGS) -o $(writeName) writeImage.c

display: displayImage.c
	$(CC) $(CFLAGS) -o $(displayName) displayImage.c

run: displayImage.c writeImage.c
	$(CC) $(CFLAGS) -o $(displayName) displayImage.c
	$(CC) $(CFLAGS) -o $(writeName) writeImage.c
	./$(writeName) $(imageName)
	./$(displayName) $(imageName)
