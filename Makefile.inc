.SUFFIXES: .fig .tex .pdf
.fig.pdf:
	fig2dev -L pdf -p xx $< $@
.tex.pdf:
	pdflatex $<
	pdflatex $<

all: slide handout release

slide: $(LECTURE).pdf
handout: $(LECTURE)_handout.pdf

$(LECTURE)_handout.tex: $(LECTURE).tex
	cp -f $< $@
	sed -e 's@\\documentclass\[@&handout,@' \
	    -e 's@{FullScreen}@{None}@' \
	    -i.bak $@

$(LECTURE).pdf: $(LECTURE).tex $(EXTRADEPENDS)
$(LECTURE)_handout.pdf: $(LECTURE)_handout.tex $(EXTRADEPENDS)

release: $(LECTURE).pdf $(LECTURE)_handout.pdf
	@apg -n 1 -m 12 | pdftk $(LECTURE).pdf output $(LECTURE)_slide.pdf owner_pw PROMPT encrypt_128bit allow
	@$(RM) -f $(LECTURE).pdf
	@apg -n 1 -m 12 | pdftk $(LECTURE)_handout.pdf output $(LECTURE)_print.pdf owner_pw PROMPT encrypt_128bit allow Printing
	@$(RM) -f $(LECTURE)_handout.pdf

clean:
	-$(RM) *.pdf *.aux *.log *.out *_handout.* *.bak *.nav *.snm *.toc *.vrb
