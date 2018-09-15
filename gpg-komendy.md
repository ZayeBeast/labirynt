- pobierz gpg (np [tutaj](https://gnupg.org/download/), wybierz te z dopiskiem `Simple installer for the current GnuPG`)
- `gpg --full-gen-key` generowanie nowego klucza gpg
- wybierz typ swojego klucza
- wybierz długość swojego klucza (czym większa, tym trudniej złamać)
- wybierz czy chcesz ustawić, żeby Twój klucz wygasał (będziesz go musiał aktualizować, co jakiś czas)
- wpisz swoje imię i nazwisko lub nick na GitHubie, w zależności od tego jak chcesz używać tego klucza
- wpisz swój email, który podałeś przy r[ejestracji na GitHubie](https://github.com/settings/emails)
- jeżeli chcesz możesz wpisać komentarz (np 'git key only'), jeżeli nie kliknij enter bez wpisywania niczego
- wpisz hasło, które będzie zabezpieczać Twój klucz, **będziesz go musiał podawać przy każdym podpisywania commita, tagu etc.**
- po wygenerowaniu klucza powinien wypisać się Twój fingerprint (np '155DC461762448AE414303B92769D6190A92139E')
- jeżeli będziesz chciał go poznać w przyszłości wpisz `gpg --fingrprint`
- `gpg -a --export-secret-key <id>` żeby wypisać swój klucz prywatny (który możesz przechowywać gdzieś zaszyfrowany w ramach backup'u)
- `gpg -a --export <fingerprint>` żeby wypisać swój klucz publiczny, który [musisz podać GitHubowi](https://github.com/settings/gpg/new) i rozesłać go użytkownikom w sieci (w naszym wypadku wszystkim uczestnikom projektu lub całemu światu)
- zaimportuj klucze [GitHuba](https://pgp.mit.edu/pks/lookup?op=get&search=0x5DE3E0509C47EA3CF04A42D34AEE18F83AFDEB23) oraz wszystkich użytkowników w sieci przez `gpg --import <nazwa pliku z kluczem>`
- żeby wyświtlić fingerprinty wszystkich kluczy wpisz `gpg --fingerprint`
- po potwierdzeniu fingerprintów z prawdziwym właścicielem klucza możesz go podpisać przez kolejno:
  -  `gpg --edit-key <id klucza do podpisania>`
  -  `sign`
  - potwierdź
  - `q`
  - i teraz możesz go wyeksportować i rozesłać w sieci
- jeżeli chcesz zobaczyć podpisy poszczególnych commitów wpisz `git log --show-signature`
  przykładowy poprawny podpis:
  ```
  gpg: Podpisano w 08/26/18 18:59:21 <8C>rodkowoeuropejski czas letni^M
  gpg:                przy u<BE>yciu klucza RSA 93F99DE4C1D27DB264ED91BD38A92C1A795C48A2^M
  gpg: Poprawny podpis z<88>o<BE>ony przez ,,Nircek-2103 <nircek-2103@protonmail.com>'' [absolutne]^M
  ```