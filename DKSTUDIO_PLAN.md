# MultiCast / DKStudio Plan

## Цель

Сделать рабочий форк `obs-aitum-multistream` под брендом `MultiCast by DKStudio`, собрать его под Windows и подготовить к публикации исходников на GitHub с соблюдением GPL.

## Что уже сделано

- Клонирован исходный репозиторий в `MultiCast`
- Выполнен основной ребрендинг на `MultiCast` / `DKStudio`
- Обновлены ссылки на `dkstudio.pro`
- Отключена проверка обновлений через API Aitum
- Добавлен локальный auth endpoint в DKStudio:
  - `GET http://127.0.0.1:4545/api/multicast/auth-state`
- Добавлен базовый lock в плагин:
  - плагин проверяет локальный DKStudio
  - без запущенного и залогиненного DKStudio стрим-кнопки блокируются

## Что важно по правам

- Это GPL-форк, поэтому исходники форка нужно публиковать открыто
- Нужно сохранить лицензию GPL и указание, что проект основан на `obs-aitum-multistream`
- Нельзя делать вид, что код полностью с нуля, если база взята из GPL-проекта
- Можно делать свой брендинг, свои фичи, свой installer и tight integration с DKStudio

## Что нельзя ломать без отдельной задачи

- Вызовы `aitum_vertical_*` пока не переименовывать
- Это похоже на совместимость с отдельным vertical plugin
- Если переименовать их сейчас, можно сломать интеграцию vertical canvas

## Следующие шаги

1. Добить ребрендинг ассетов
   - заменить временную иконку `media/aitum.png` на свою `multicast.png`
   - проверить `resource.rc.in`, installer assets, package names

2. Дожать auth-lock
   - блокировать не только start, но и создание/редактирование output при необходимости
   - при желании добавить проверку edition / лицензии / токена

3. Собрать локально под Windows
   - использовать `CMakePresets.json`
   - использовать `.github/scripts/Build-Windows.ps1` как ориентир
   - если локально не хватает OBS deps, собрать через GitHub Actions

4. Подготовить GitHub fork
   - сменить README, releases naming, workflow display names
   - проверить package output names
   - настроить свой repo и releases

5. Подготовить установщик
   - проверить имя DLL, installer title, release artifact names
   - убедиться, что пользователь видит `MultiCast by DKStudio`

## Рекомендуемый порядок

1. Закончить ребрендинг визуала и ассетов
2. Прогнать первую сборку
3. Исправить compile/runtime ошибки
4. Настроить GitHub Actions под твой репозиторий
5. Собрать installer
6. Потом уже усиливать связку с DKStudio

