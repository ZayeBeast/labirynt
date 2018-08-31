pierwsze ustawienia po instalacji gita
# wszystkie rzeczy wykonywać w Git Bash (na linuxach nie ma problemu)
# ważne <email> powinien być taki, który jest połączony z GH
# wszystkie takie możesz sprawdzić tu https://github.com/settings/emails
ssh-keygen -t rsa -b 4096 -C "<email>" # generowanie nowego klucza
# teraz klikaj cały czas enter
eval $(ssh-agent -s) # uruchamienia agenta ssh
ssh-add ~/.ssh/id_rsa # dodawanie klucza do agenta ssh
notepad ~/.ssh/id_rsa.pub # wyświetlenie Tw klucza publicznego w notatniku
# skopiuj to co Ci się wyświetli
# wejdź na https://github.com/settings/ssh/new i wklej w pole 'Key'
# a w Title napisz dowolną nazwę, która będzie identyfikowała komputer, na którym aktualnie pracujesz
ssh -T git@github.com # testowanie połączenia z GH
# wpisz yes, jeżeli ktoś Cię o to zapyta
# jeżeli wypisało Ci 'You've successfully authenticated' to poprawnie połączyłeś Gita z GitHubem
git config --global user.name "<nick z GH>" # ustawianie nicka dla commitów
git config --global user.email <email> # ustawianie emaila dla commitów
git config --global user.signingkey <gpg-key-id> # ustawianie klucza do podpisywania commitów, przy czym gpg musi być w PATH

tworzenie nowego repo lokalnie
# stwórz nowy folder gdzie chcesz mieć swój projekt (lub wejdź do folderu ze starym projektem)
git init # stworzenie repo
git add * # dodanie wszystkich plików do rejestrowania
git commit # stworzenie commita inicjalizującego (ze wszystkim, co było tam do tej pory)

... i dodanie go na serwer
# wejdź na https://github.com/new i stwórz nowe repo
git remote add origin git@github.com:<username>/<nazwa repo na GH>.git
git push -u origin master

sklonowanie repo z serwera (jeżeli chcecie mieć możliwość pushowania commitów musicie oprosić autora o uprawnienia lub zrobić swojego forka)

commitowanie zmian w pliku

dodawanie nowego pliku do repo

tworzenie nowej gałęzi

... i przechodzenie na nią

... lub prościej (create&switch)
git checkout -b <nazwa>

pushowanie nowej gałęzi na serwer
git push -u origin <nazwa>

pushowanie commitów (wrzucanie ich na serwer)
git push

pullowanie commitów (pobieranie commitów z serwera)
git pull
