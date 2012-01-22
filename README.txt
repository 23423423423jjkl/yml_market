
--------------------------------ENGLISH-------------------------------
This module defines set of views plugins and handlers that allows you to generate
YML file for http://yandex.market.ru. It's up to you to decide what fields you
want to send to Yandex. 

There two ways of creating YML file:

-------------

I. From scratch (Long method).

1. Create new View

2. Add field you want to be in YML file using standart views method.
Some tips:
-Select such fields and formating of fields that haven't got any html markup.
-Don't check "Link this field to its node" in any field.
-If you use Ubercart, in "Sell price" field select Numeric format.
-For images select format "URL to file".
-For "link to item" YML field use "Yandex market: Node url" views field.
-For categories use "Yandex market: One term id" field.
-Use fields from "Yandex market" category if you can.

3.Select views style:"yandex market".

4.In "Style options" select correspondence between views fields and YML fields.
Be careful in this step. Yandex can reject your store, if you select incorrect fields.

5.Add views display "Page with no layout".

6.In "Page settings" block enter Path. Here your YML will be. This path 
you should enter in Yandex market administrative interface.

7.Optional. Change "Items to display" setting to 0.

8.Optional. Check "Distinct" setting.

9.Optional. Add filters, arguments etc. if you need. 
Don't forget that usually you want to display only few node types.

10.Save your view. Be happy.

---------------

II. Using Default views (Short method).
1.At /admin/build/views enable "yandexmarket" default view.
2.Add fields you want. See paragraph number 2 in first method.
3.Set correspondence between YML fields and views fields on style options page.
See paragraph number 4 in first method.
4.Set filter to show only nodes you want.
5.Save your view. Now YML file is available at http://example.com/yandexmarket

--------------------------------RUSSIAN-------------------------------
Существует два способа создания YML файла с помощью этого модуля:

------------

I.С нуля (длинный способ).

1.Создайте новое представление(View)
Администрирование->Конструкция сайта->Представления->Добавить
Ввести название
Выбрать тип представления: Материал
Нажать "Следующий"
2.Добавить поля, которые будут выдаваться Яндексу.
Выбирайте такие поля, которые будут выводиться без html тегов. В частности:
-не ставьте галочку "Link this field to its node"
-если вы используете Ubercart, у цены(Sell price) выберите формат Numeric с точкой 
в роли разделителя дробной части.
-для картинок выбирайте формат "URL to file"
-Для ссылки на товар можете использовать поле "Yandex market: Node url"
-Для категоризации товаров используйте поле "Yandex market: One term id"
-По возможности используйте поля из категории "Yandex market"

3.Выберите стиль представления "yandex market"
Кликните на текущий стиль рядом с пунктом "style"(скорее всего это будет "Unformatted").
Выберите в появившемся списке "Yandex market"
Нажмите "Update default display"

4.В появившихся свойствах стиля укажите соответствия между полями Views и полями YML.
-Currencies на данный момент необходимо вводить как xml (если ваш магазин использует 
только рубли, можно оставить значение по умолчанию)
-Выберите словарь Таксономии, термины которого, будут использоваться в качестве категорий
-Пункты ниже это поля для каждого предложения в YML файле. Для каждого поля 
доступны следующие значения:
-<None> : данный тег/атрибут показываться не будет
-<Static> :  необходимо ввести в поле Static value значение, которое
для всех товаров будет одинаково.
-Так же можно выбрать одно из полей, которое вы добавляли в пункте 2

Обязательно заполните следующие поля:
id - скорее всего это будет поле nid продукта
available - TRUE если вы предоставляете товар сразу, FALSE если на заказ
type - тип товара. Если все товары в Вашем магазине одинакового типа можно 
выбрать <Static> и вписать нужный тип(vendor.model, book, artist.title, tour, ticket, event-ticket).
Если товары разного типа, то можно добавить соответствующее CCK или Сomputed field
url - ссылка на товар. Можно выбрать "Материал: Node url"
price - цена. Можно выбрать "Sell Price" если Вы используете Ubercart
currencyId - валюта. Если Ваш магазин использует только рубли выберите Static Value 
и введите "RUB"
categoryId - tid термина из словаря таксономии, который был выбрать в поле "Vocabulary".
Можно использовать значение "Yandex market: One term id".
name - названия товара. можно выбрать "Материал: название"

Внимательно отнеситесь к заполнению остальных полей. Yandex может прекратить показ товаров,
если ему что то не понравится.

Нажмите "Update default display".

5.Выберите слева над кнопкой "Add display" в выпадающем списке значение "Page with no layout".
Нажмите "Add diaplay".

6.В разделе "Page settings" измените "Путь" на путь к странице. Ссылку на эту страницу потом
нужно будет ввести в административном интерфейсе Яндекса. Этот путь не должен быть словом "yandex".

7.Необязательно. Поменяйте значение "Items to display" на 0, что бы показывать все значения.

8.Необязательно. Поставьте галочку в поле "Distinct", что бы не выводить дублирующих товаров.

9.Необязательно. Добавьте необходимые фильтры, аргументы и др.
Не забудьте поставить такие фильтры, что бы выводились только нужные вам материалы.

10.Сохраните Представление.

-------------

II. Используя Представления по умолчанию(Default views).
1.на странице /admin/build/views включите Представление "yandexmarket".
2.Добавьте поля, которые Вы хотите показывать Яндексу. 
В пункте 2 первого способа Вы найдете более подробное описание этого шага.
3.Установите соответствие между YML полями и Views полями на странице настроек стиля.
В пункте 4 первого способа Вы найдете более подробное описание этого шага.
4.Установите необходимые фильтры.
5.Сохраните Представление. Теперь YML файл доступен по адресу http://example.com/yandexmarket