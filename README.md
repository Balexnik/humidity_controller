# humidity_controller
## Назначение 
Контроль уровня относительной влажности психрометрическим методом

## Формула
Из разницы показаний температур определяется текущее давление водяного пара в воздухе по формуле
```
e = E(t_w) - A * P * (t_d - t_w)
```
где 
* E(t_w) — давление насыщения при температуре смоченного термометра,
* A — постоянная психрометра, принимаемая равной 0.0007947,
* P — атмосферное давление, принимается равным 1000 гПа
* t_d — показания сухого термометра
* t_w — показания смоченного термометра

И наконец, относительная влажность воздуха — это соотношение текущего давления к давлению насыщения при данной температуре воздуха

```
f = 100 * e / E (t_d)
```
где
* E(t_d) — давление насыщения при температуре сухого термометра

## Ссылки
* http://www.vbrspb.ru/files/20131211-143614_529808899.PDF
* https://ru.wikipedia.org/wiki/%D0%9E%D1%82%D0%BD%D0%BE%D1%81%D0%B8%D1%82%D0%B5%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D0%B2%D0%BB%D0%B0%D0%B6%D0%BD%D0%BE%D1%81%D1%82%D1%8C
* https://planetcalc.ru/246/
