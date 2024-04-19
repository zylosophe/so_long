#!/bin/sh
for PNG in $(find . -type f -name "*.png")
do
	# resize
	convert "$PNG" -resize x30 "$PNG"
	# extract color and alpha
	convert "$PNG" -negate -alpha opaque "${PNG%.png}.xpm"
	convert "$PNG" -alpha extract "${PNG%.png}.alpha.xpm"
	rm "$PNG"
done
