#include <stdio.h>
#include <string.h>
int
main(int argc, char *argv[])
{
	FILE           *infile, *outfile;

	outfile = fopen("outfile.txt", "wt");

	if ((infile = fopen(argv[1], "r")) == NULL) {
		perror("Error");
		exit(1);
	}

	char		data      [1];
	char		tc;
	int		i;
	int		b;
	int		cary       [255] = {0};

	memset(data, 0, sizeof(data));



	while ((tc = (fread(data, 1, 1, infile))) == 1) {
		cary[data[0]]++;
		if (data[0] > 32)
			fwrite(data, 1, 1, outfile);

	}



	for (i = 0; i <= 255; i++) {
		for (b = 0; b < cary[i]; b++) {
			printf("%c", i);
		}
	}
	printf("\n");

	fclose(infile);

	//fclose(outfile);

}
