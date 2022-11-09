24.5 Практическая работа

Задача
Цели домашнего задания
1. Получить практический навык работы со временем и датами в C++.
2. Научиться:

3. запрашивать текущее актуальное время;
получать информацию о дате от пользователя;
выводить даты в нужном формате;
производить простейшие манипуляции со временем.

Что входит в домашнее задание
Реализовать программу учёта времени.
Реализовать программу напоминания о днях рождения.
Реализовать вывод выбранного времени года.



# **Задание 1. Реализация программы учёта времени**

Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

Пользователь взаимодействует с программой с помощью команд:
Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести 
название задачи, над которой он планирует сейчас работать. Если уже была начата какая-то другая задача,
предыдущая должна быть автоматически завершена и начата новая.

Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено.
Также выводится название текущей выполняемой задачи, если таковая имеется.
Команда exit выходит из программы.


_Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено._

Что оценивается
Корректность работы программы.


# **Задание 2. Реализация программы напоминания о днях рождения**

Что нужно сделать

Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: вводит имя друга
и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. Сигналом окончания ввода дней 
рождения является “end” введённое в качестве имени.

После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит его на экран 
вместе с именем в удобном, локальном формате - месяц/день. Если день рождения уже был в этом году, данные о
пользователе пропускаются. Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное
сообщение об этом. Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь
дни рождения в один день.

_Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты std::tm._

Что оценивается
Корректность работы программы.


# **Задание 3. Реализация программы таймера**

Что нужно сделать

Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере,
и нажимает «Ввод». После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно
сообщается пользователю. Формат вывода такой же, как и при вводе интервала: минуты и секунды.

Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального сообщения.
Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!


_Советы и рекомендации
Для ввода значения для засекания времени используйте std::get_time, но в качестве формата запросите только 
минуты и секунды. Целевое время для остановки таймера вычислите сами с помощью манипуляции над текущим std::time. 
Количество оставшегося времени выводите в цикле и вычислите его самостоятельно с помощью обращения с
типом std::time_t как с секундами._


Что оценивается
Корректность работы программы при разных заданных дефинициях макросов.
