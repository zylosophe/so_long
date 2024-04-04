#!/bin/sh
for PNG in $(find . -type f -name "*.png")
do
	convert "$PNG" -alpha opaque "${PNG%.png}.xpm"
	convert "$PNG" -alpha extract "${PNG%.png}.alpha.xpm"
	rm "$PNG"
done
