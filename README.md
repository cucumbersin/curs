# curs
start

Предметная область:Продажа авиабилетов<br/>
Метод хеширования:Закрытое хеширование с квадратичным опробованием<br/>
Метод сортировки:Быстрая (Хоара)<br/>
Вид списка:Линейный однонаправленный<br/>
Метод обхода дерева:Обратный<br/>
Алгоритм поиска слова в тексте:Боуера и Мура (БМ)<br/>

9.5. Продажа авиабилетов<br/>
9.5.1. Информационная система для предметной области «Продажа авиабилетов» должна осуществлять ввод, хранение, обработку и вывод данных о:<br/>
– пассажирах;<br/>
– авиарейсах;<br/>
– продаже и возврате авиабилетов.<br/>
9.5.2. Данные о каждом пассажире должны содержать:<br/>
– Номер паспорта – строка формата «NNNN-NNNNNN», где N – цифры;<br/>
– Место и дата выдачи паспорта – строка;<br/>
– ФИО – строка;<br/>
– Дату рождения – строка.<br/>
Примечание: длина строк (кроме номера паспорта) определяетсястудентом самостоятельно.<br/>
9.5.3. Данные о пассажирах должны быть организованны в виде хеш-таблицы, первичным ключом которой является «номер паспорта». Метод хеширования определяется вариантом задания.<br/>
9.5.4. Данные о каждом авиарейсе должны содержать:<br/>
– Номер авиарейса – строка формата «AAA-NNN», где AAA – код авиакомпании (буквы латиницы); NNN – порядковый номер авиарейса (цифры);<br/>
– Название авиакомпании – строка;<br/>
– Аэропорт отправления – строка;<br/>
– Аэропорт прибытия – строка;<br/>
– Дату отправления – строка;<br/>
– Время отправления – строка;<br/>
– Количество мест всего – целое;<br/>
– Количество мест свободных – целое.<br/>
Примечание: длина строк (кроме «номер авиарейса») определяется студентом самостоятельно.<br/>
9.5.5. Данные об авиарейсах должны быть организованны в виде АВЛ-дерева поиска, упорядоченного по «номеру авиарейса».<br/>
9.5.6. Данные о выдаче или возврате авиабилета должны содержать:<br/>
– Номер паспорта – строка, формат которой соответствует аналогичной строке в данных о пассажирах;<br/>
– Номер авиарейса – строка, формат которой соответствует аналогичной строке в данных о авиарейсах;<br/>
– Номер авиабилета – строка из 9 цифр;<br/>
Примечания:<br/>
1. Наличие в этих данных записи, содержащей в поле «номер паспорта» значения X и в поле «номер авиарейса» значения Y, соответственно означает продажу авиабилета пассажиру с номером паспорта X<br/>
на авиарейс с номером Y. Отсутствие такой записи означает, что пассажир с номером паспорта X не покупал билета на авиарейс с номером Y.<br/>
2. На один авиарейс может быть продано несколько билетов. Таким образом, могут быть данные, имеющие повторяющиеся значения в некоторых своих полях.<br/>
9.5.7. Данные о продаже или возврате авиабилетов должны быть организованны в виде списка, который упорядочен по первичному
ключу – «номер авиабилета». Вид списка и метод сортировки определяются вариантом задания.<br/>
9.5.8. Информационная система «Продажа авиабилетов» должна осуществлять следующие операции:<br/>
– регистрацию нового пассажира;<br/>
– удаление данных о пассажире;<br/>
– просмотр всех зарегистрированных пассажиров;<br/>
– очистку данных о пассажирах;<br/>
– поиск пассажира по «номеру паспорта». Результаты поиска – все сведения о найденном пассажире и номерах авиарейсов, на который он купил билет;<br/>
– поиск пассажира по его ФИО. Результаты поиска – список найденных пассажиров с указанием номера паспорта и ФИО;<br/>
– добавление нового авиарейса;<br/>
– удаление сведений об авиарейсе;<br/>
– просмотр всех авиарейсов;<br/>
– очистку данных об авиарейсах;<br/>
– поиск авиарейса по «номеру авиарейса». Результаты поиска – все сведения о найденном авиарейсе, а также ФИО и номера паспортов пассажиров, которые купили билет на этот авиарейс;<br/>
– поиск авиарейса по фрагментам названия аэропорта прибытия.<br/>
Результаты поиска – список найденных авиарейсов с указанием номера авиарейса, аэропорта прибытия, даты отправления, времени
отправления;<br/>
– регистрацию продажи пассажиру авиабилета;<br/>
– регистрацию возврата пассажиром авиабилета.<br/>
9.5.9. Состав данных о пассажирах или авиарейсах, выдаваемых<br/>
при просмотре всех зарегистрированных пассажиров или просмотре всех авиарейсов, определяется студентом самостоятельно, но
должен содержать не менее двух полей.<br/>
9.5.10. Метод поиска пассажира по ФИО определяется студентом
самостоятельно. Выбранный метод необходимо сравнить с альтернативными методами.<br/>
9.5.11. Поиск авиарейса по фрагментам названия аэропорта прибытия должен осуществляться путем систематического обхода
АВЛ-дерева поиска. Метод обхода определяется вариантом задания.<br/>
При поиске авиарейса по фрагментам «Аэропорт прибытия» могут
быть заданы как полное наименование аэропорта, так и его часть.<br/>
Для обнаружения заданного фрагмента в «Аэропорту прибытия»
должен применяться алгоритм поиска слова в тексте, указанный
в варианте задания.<br/>
9.5.12. Регистрация продажи авиабилета на определенный авиарейс должна осуществляться только при наличии свободных мест
на этот авиарейс.<br/>
9.5.13. При удалении данных об авиарейсе должны быть учтены
и обработаны ситуации, когда на него уже зарегистрированы пассажиры. Аналогичным образом следует поступать и с удалением данных о пассажирах.<br/>
