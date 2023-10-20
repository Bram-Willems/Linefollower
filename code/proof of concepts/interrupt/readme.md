# Proof of concepts

Starten en stoppen van de robot moet ook met een fysieke monostabiele schakelaar op de robot kunnen. Deze schakelaar cyclisch gaan afvragen is geen goed idee. Dit kan enerzijds de timing van de rest van het programma in de war sturen en anderzijds riskeer je pulsen te missen. De schakelaar aan een externe interrupt van de microcontroller hangen en deze hardwarematig te bewaken is een stuk handiger.

Debouncen van de schakelaar kan je hard- of softwarematig doen. Of beide.
