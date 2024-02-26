# How to import assets?
1. `sudo apt install magickimage`
2. cd to a directory where there is *only* .png files (or subdirectories)
3. Execute
```sh
for PNG in $(find . -type f)
do
	convert "$PNG" "${PNG%.png}.xpm"
	convert "$PNG" -alpha export "${PNG%.png}.alpha.xpm"
	rm "$PNG"
done
```
