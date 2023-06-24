# DV1627 Projekt: Spel

## Vad ska du göra?

I detta projekt ska du tillämpa innehållet i kursen och strukturera en egen problemlösning med klasser och objekt. Din uppgift är att implementera ett enkelt spel, och skriva en kort rapport där du beskriver hur du löst problemet och uppfyller projektet kriterier. 

Projektuppgiften betygsätts från A-F. Genom att implementera en spelet enligt givna kriterier, samt ger svar på efterfrågade punkter i rapporten, så når du betyget E. För ett högre betyg behöver du lösa fler problem.

Efter denna nivå finns det ett fyra olika extraval som bygger vidare på grundspelet, där varje extraval har egna kriterier som måste uppfyllas. Varje extraval du implementerar, och uppfyller kritierer för, ökar ditt betyg med en nivå. Det finns ingen ordning på dessa extraval, du får blanda dessa fritt i vilken ordning du själv är bekväm med. Se följande lista för betygsättning:

- Betyg E: grundspel + rapport
- Betyg D: grundspel + rapport + 1 extraval
- Betyg C: grundspel + rapport + 2 extraval
- Betyg B: grundspel + rapport + 3 extraval
- Betyg A: grundspel + rapport + 4 extraval

Notera att ett extraval måste vara fulltständigt implementerat enligt dess kriterier för att uppnå sin poäng. Halvfärdiga, eller "nästan färdiga", lösningar räknas ej.

## Hur ritar du objekt till ett fönster?

För att kunna skapa ett fönster och rita objekt kommer du använda ett färdigt bibliotek med namnet SFML (Simple and Fast Multimedia Library). Med detta bibliotek kan du snabbt och smidigt komma igång med att rita objekt.

Följande kodexempel skapar ett fönster och ritar en grön cirkel från kant-till-kant i fönstret:
```cpp
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```

För att komma igång får du en del exempelkod att utgå ifrån (samma som vid förra tillfället). Det är helt okej att använda den koden som ges, men det är ingen krav att den måste användas. Syftet med koden är att introducera exempelvis:
- Hur du skapar grunden för att köra ett visuellt projekt med SFML.
- Hur du kan skapa egna klasser för spelobjekt som ska...
	- uppdateras över tid (exempelvis position).
	- ritas till fönstret med ny position.
- Matematik för att beräkna...
	- ny position baserat på en riktning och hastighet över tid.
	- avstånd mellan två positioner.
	- rotationsvinkel baserat på en viss riktning. 

## Betygskriterier

**För betyget E:**
 
- Spelet ska vara fullt fungerande 
    - den enhet spelaren styr (kallad side-slider) kan endast röra sig utmed vänster fönsterkant Klar
    - spelaren styr side-slidern med piltangenterna pil-upp och pil-ner Klar
    - meteoriter kommer slumpmässigt från höger mot vänster och det finns minst 3 av dessa
    - spelaren har ett visst antal liv vilket ska synliggöras i spelfönstret (ex-vis med uppritade hjärtan eller cirklar)
    - spelaren ska kunna skjuta en kula från side-slidern horisontellt genom att trycka på space-tangenten
    - kulan har en viss räckvidd (dvs den når en viss distans)
    - när kulan avverkat distansen placeras den åter hos side-slidern
    - om kulan träffar en meteorit placeras kulan åter hos side-slidern
    - om kulan träffar en meteorit "sker/visas" en explosion och meteoriten "försvinner". Det är dock okej (och rekommenderat) att "återanvända" meteoriter igen istället för att avallokera och skapa nya.
    - om meteoriten träffar fönstrets vänstra kant förlorar spelaren ett liv och meteoriten "försvinner"
    - när spelet är över ska detta visas med texten Game-Over i spelfönstret
    - spelaren börjar med tre (3) liv. Spelet fortsätter tills att spelaren har 0 liv och förlorar, dvs. när tre olika meteorieter har nått vänster fönsterkant. 
    - spelarens uppgift är alltså att förstöra meteoriter innan de når fönstrets vänstra kant för att fortsätta spela. 
    - spelarens kvarvarande liv ska visualiseras på något vis, exempelvis genom att rita tre symboler eller en siffra i hörnet av fönstret.
    - spelet kan påbörjas direkt programmet startar. När spelet är över ska spelaren presenteras med texten "Game Over" följt av att programmet kan avslutas.

- Inga minnesläckor får genereras.
- Inga globala variabler får finnas.
- Lösningen ska vara objektorienterad, dvs uppbyggd av egendefinerade klasser för vilka objekt skapas. Du ska definiera minst 3 olika klasser. Observera att klasserna ska definiera olika typer av objekt.
- Alla medlemsvariabler ska vara privata.
- Arv och polymorfism (dynamisk bindning) ska utnyttjas på ett logiskt och rimligt sätt.
- Minst en abstrakt klass ska finnas.
- Alla objekt som finns i spelet ska allokeras på heapen.
- Det ska finnas en array/behållare där pekare till objekt av samma basklasstyp ska samlas.
- Det är tillåtet att använda en behållare från standardbiblioteket för detta, exempelvis `std::vector`.

- Det är tillåtet att använda allt från standardbiblioteket (`std`)
    - Detta inkluderar exempelvis `vector`, smartpekare etc.


**Extraval för högre betyg:**
- **Meny**
    - Ska presenteras för spelaren när programmet startar, och återgås till när spelet är över.
    - Det ska inte finnas någon gräns för hur många gånger spelet kan startas från menyn och återgå tillbaka. Rekursion är alltså **inte** ok här.
    - Det ska *åtminstone* finnas två val för spelaren att välja mellan i menyn: starta spelet och avsluta.
- **Sköld**
    - Det ska finnas en sköld som side-slidern kan använda under en begränsad tid. Denna sköld är placerad framför (till höger om) side-slidern och följer med side-sliderns rörelse. Skölden skyddar mot meteoriterna.
- **Spelrundor**
    - Istället för ett kontinuerligt spel som bara tar slut när spelaren förlorar ska det finnas "spelrundor".
    - Under en spelrunda ska det skapas ett bestämt antal meteoriter.
    - Spelaren vinner en spelrunda när alla meteoriter i den rundan är förstörda.
    - Det ska finnas någon tydlig indikation att en ny spelrunda påbörjas, exempelvis en viss text i fönstret.
    - Antalet meteoriter ska öka för varje spelrunda. Exempelvis kan första rundan innehålla tre (3) meteoriter, andra rundan tio (6) meteoriter, tredje rundan femton (9) meteoriter osv.
- **Highscores**
    - Spelaren ska samla någon form av poäng under sitt spelande. Exempelvis kan spelaren få poäng baserat på speltid, eller antalet meteoriter som spelaren förstör.
    - Under speltid ska spelaren alltid se sin nuvarande poäng. Exempelvis kan poängen ritas som siffra i ett av hörnen på fönstret.
    - Upp till fem (5) högsta poängresultat ska lagras till en fil mellan programkörningar. Poängen i filen ska lagras i ordning.
    - När spelet är över ska spelarens poäng jämföras med de tidigare högsta poängresultaten i den sparade filen, och skrivas in i filen om nuvarande poäng är del av de fem högsta poängresultaten. Detta kan innebära att om det redan finns fem (5) resultat sen tidigare ska nuvarande poäng skriva över en av dessa.
    - När spelet är över ska resulterande poäng presenteras för spelaren, samt den uppdaterade listan av de fem (5) högsta poängen. 
    - Det är tillåtet, men inget krav, att spelaren ska skriva sitt namn för sin poäng.

**Vad rapporten ska innehålla**

Rapporten ska vara renskriven på antingen svenska eller engelska. Renskriven innebär att du ska läsa igenom och åtgärda språk- och stavfel. Använd gärna program som Microsoft Word eller Google Docs som hjälper dig med detta.

Det finns ingen strikt gräns för antal ord i rapporten, men följande punkter ska ingå: 

1. Vilket betyg du strävar efter med din implementation.
2. Ett klassdiagram som visar en överblick av dina klasser i programmet.
    - Klassnamn och relationer ska presenteras.
    - Viktiga funktioner och variabler i klasser ska presenteras. Du behöver inte visa alla funktioner och variabler i klasser. 
3. Beskriv på vilket sätt du uppfyller kravet på 
    - logiskt och rimligt arv 
    - polymorfism
4. Förklara hur du uppfyllt kraven för det betyg du strävar efter.
    - I din motivation ska det tydligt framgå att du uppfyller samtliga kriterier för betyget.
5. Argumentera för- och nackdelar med din implementation.
    - Vad har du lärt dig på vägen?
    - Vad hade du gjort annorlunda om du skulle göra om projektet idag?

## Tips

- Skapa en abstrakt basklass `SceneObject` som alla spelobjekt ärver från, exempelvis kula och meteoriter.
    - Detta gör det möjligt att hantera alla scenobjekt med polymorfism. Exempelvis kan denna klass ha de (rent) virtuella funktionerna `Update` och `Draw` (från `sf::Drawable`) som alla scenobjekt kan välja att överskugga.
    - Notera att det finns ett kriterie som säger att objekt av samma basklasstyp ska lagras i samma array/behållare, och detta uppfyller kriteriet. Det finns inget som hindrar fler typer av scenobjekt att finnas i samma samling. :)
- Skapa en behållarklass `Scene` som hanterar lagrar alla scenobjekt.
    - Detta gör ett lättare hantera alla scenobjekt. Exempelvis kan scenen ha en funktion `Update` som i sig itererar och kallar på `Update` för samtliga scenobjekt.
- För att känna av tangent-nedtryckning av A kan följande användas 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 