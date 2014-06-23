CFLAGS = 
CWEAVE = cweave +d
CTANGLE = ctangle
.SUFFIXES: .tex .dvi .w

.w.tex:
	$(CWEAVE) $*

.tex.dvi:	
	tex $*


.w.dvi:
	$(CWEAVE) $*
	tex $*

.w.c:
	$(CTANGLE) $*


.w.o:
	$(CTANGLE) $*
	$(CC) $(CFLAGS) -c $*.c

manual.dvi: compare.tex
