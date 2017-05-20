SUBS = app1 app2 

.SILENT:

it install bare clean depend:
	-BASEPWD=`pwd`; \
	for i in $(SUBS); do \
		echo '<<' $$i '>>'; \
		cd $$BASEPWD/$$i; \
		make $@ ; \
	done
