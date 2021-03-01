run: main.o PoliticianLeaderDemocratic.o PoliticianSocialDemocratic.o Democratic.o Leader.o Party.o PoliticalSys.o Politician.o Republican.o PoliticianLeaderRepublican.o PoliticianSocialRepublican.o Social.o
	g++  main.o PoliticianLeaderDemocratic.o PoliticianSocialDemocratic.o Democratic.o Leader.o Party.o PoliticalSys.o Politician.o Republican.o PoliticianLeaderRepublican.o PoliticianSocialRepublican.o Social.o -o run

main.o: main.cpp PoliticalSys.h Politician.h Party.h Republican.h Leader.h Social.h Democratic.h PoliticianSocialDemocratic.h PoliticianLeaderDemocratic.h PoliticianLeaderRepublican.h PoliticianSocialRepublican.h Error.h
	g++ -c main.cpp

PoliticianLeaderDemocratic.o: PoliticianLeaderDemocratic.cpp PoliticianLeaderDemocratic.h Politician.h Leader.h
	g++ -c PoliticianLeaderDemocratic.cpp


PoliticianSocialDemocratic.o: PoliticianSocialDemocratic.cpp PoliticianSocialDemocratic.h Politician.h Social.h
	g++ -c PoliticianSocialDemocratic.cpp

Democratic.o: Democratic.cpp Democratic.h Party.h Politician.h
	g++ -c Democratic.cpp

Leader.o: Leader.cpp Leader.h Politician.h Party.h
	g++ -c Leader.cpp

Party.o: Party.cpp Party.h Politician.h
	g++ -c Party.cpp

PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Politician.h Party.h Republican.h Leader.h Social.h Democratic.h PoliticianSocialDemocratic.h PoliticianLeaderDemocratic.h PoliticianLeaderRepublican.h PoliticianSocialRepublican.h Error.h
	g++ -c PoliticalSys.cpp

Politician.o: Politician.cpp Politician.h Party.h
	g++ -c Politician.cpp

Republican.o: Republican.cpp Republican.h Party.h Politician.h
	g++ -c Republican.cpp

PoliticianLeaderRepublican.o: PoliticianLeaderRepublican.cpp PoliticianLeaderRepublican.h Politician.h Leader.h
	g++ -c PoliticianLeaderRepublican.cpp

PoliticianSocialRepublican.o: PoliticianSocialRepublican.cpp PoliticianSocialRepublican.h Politician.h Social.h
	g++ -c PoliticianSocialRepublican.cpp

Social.o: Social.cpp Social.h Politician.h Party.h
	g++ -c Social.cpp

clean :
	rm -f *.o run
	echo Clean done
