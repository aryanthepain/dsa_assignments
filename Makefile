#to add to github repo
#make git m="message" b="your-branch(main by defualt)"
b?=main
m?=$(shell date '+%Y-%m-%d %H:%M:%S')
git: 
	git add .
	git commit -m "$(m)"
	git push origin $(b)

push:
	git push origin $(b)

# Phony targets
.PHONY: all clean
