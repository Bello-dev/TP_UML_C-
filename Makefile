compile:
	@c++ -o prog *.cpp && clear && echo "Compilation termineé !"

run:
	@./prog


clean:
	@rm -f ./prog && clear && echo "Exécutable supprimé avec succès !"	