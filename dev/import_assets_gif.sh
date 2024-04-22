#!/bin/sh
for PNG in $(find . -type f -name "*.gif")
do
	convert "$PNG" -alpha opaque "${PNG%.gif}.xpm"
	convert "$PNG" -alpha extract "${PNG%.gif}.alpha.xpm"
	rm "$PNG"
done
