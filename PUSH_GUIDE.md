# MultiCast Push Guide

## 0. Где работать

Рабочая папка:

`C:\Users\rusga\Downloads\scratch\dkstudiopro\MultiCast`

## 1. Что уже готово

- ребрендинг под `MultiCast by DKStudio`
- локальная Windows сборка проверена
- GitHub Actions для build/release уже лежат в репо
- `.gitignore` подготовлен, чтобы не пушить build-мусор

## 2. Что создать на GitHub

Создай новый репозиторий:

- Name: `multicast` или `obs-multicast`
- Visibility: `Public`
- без auto README
- без auto `.gitignore`
- без auto License

Почему `Public`:

- это GPL fork
- так правильнее по лицензии

## 3. Что заливать

Заливать нужно содержимое папки `MultiCast`, но не build-мусор:

- `build_x64` не пойдет
- `.deps` не пойдет
- `release` не пойдет

Они уже скрыты через `.gitignore`.

## 4. Команды на первый push

Открой PowerShell в папке:

`C:\Users\rusga\Downloads\scratch\dkstudiopro\MultiCast`

Команды:

```powershell
git status
git add .
git commit -m "Initial MultiCast fork"
git branch -M main
git remote add origin https://github.com/YOUR_NAME/YOUR_REPO.git
git push -u origin main
```

Если репозиторий еще не инициализирован:

```powershell
git init
git add .
git commit -m "Initial MultiCast fork"
git branch -M main
git remote add origin https://github.com/YOUR_NAME/YOUR_REPO.git
git push -u origin main
```

## 5. Где потом смотреть сборку

На GitHub:

- вкладка `Actions`
- workflow `Push`
- внутри будет `Build MultiCast`

## 6. Что ты получишь

После успешной сборки:

- Windows artifacts
- Linux artifacts
- macOS artifacts

Windows тебе сейчас важнее всего.

## 7. Где скачать готовое

После завершения workflow:

1. Открываешь нужный run
2. Внизу ищешь `Artifacts`
3. Скачиваешь Windows artifact

Если сделаешь tag релизом, workflow может подготовить release assets автоматически.

## 8. Как сделать release через tag

Когда захочешь релиз:

```powershell
git tag 1.0.8
git push origin 1.0.8
```

После этого `push.yaml` попробует собрать release assets под tag.

## 9. Если нужен именно installer

Варианты:

1. Через GitHub Actions release artifacts
2. Локально через Inno Setup

Если локально:

- установить `Inno Setup 6`
- потом уже собирать installer отдельно

## 10. Если нужен просто ручной тест в OBS

Локально у тебя уже есть build:

`release\RelWithDebInfo\multicast`

Обычно ручная установка выглядит так:

- `multicast.dll` -> `obs-studio\obs-plugins\64bit`
- `multicast\data` -> `obs-studio\data\obs-plugins\multicast`

## 11. Что делать после первого пуша

1. Проверить Actions
2. Скачать Windows artifact
3. Проверить плагин в OBS
4. Если все ок, сделать первый release tag
5. Потом уже дорабатывать и публиковать новые версии

