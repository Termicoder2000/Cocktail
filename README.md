# Cocktail Shopping List

A C++ desktop application built with Qt Widgets for planning cocktails and preparing a combined shopping list. Choose cocktails and their quantities, then view the ingredients and total amounts needed. You can also add your own cocktails, recipes, and ingredients.

## Features

- Browse the cocktail collection and set how many of each cocktail you want to make.
- View a shopping list with matching ingredients combined and quantities scaled to the selected cocktail counts.
- Quantities are shown in milliliters for liquids and pieces for non-liquid ingredients.
- Add cocktails with a name, preparation instructions, and one or more ingredients.
- Specify each ingredient's quantity, whether it is liquid, and its alcohol percentage.
- Filter cocktails by minimum and maximum alcohol content or by selected ingredients.
- Calculate and display each cocktail's alcohol content from its liquid ingredients.

## Requirements

- C++17-compatible compiler
- Qt with the Widgets module
- Qt Creator or another qmake-compatible build environment

## Build and run with Qt Creator

1. Open `Cocktail_2.pro` in Qt Creator.
2. Select a configured Qt kit with a C++17-compatible compiler.
3. Build and run the project.

The application reads and writes its cocktail data in `Liste.txt`. Run the application with the project directory as its working directory so the data file can be found and new cocktails are saved alongside it. Keep a backup of `Liste.txt` if you want to preserve your cocktail collection.

## Data

`Liste.txt` contains the cocktail collection, including names, instructions, alcohol percentages, and ingredient details. The application loads this file at startup and appends newly created cocktails to it.

## Project structure

- `main.cpp`: Qt application entry point.
- `mainwindow.*` and `mainwindow.ui`: Main window setup.
- `meinwidget.*`: Main interface, filtering, quantities, and shopping-list display.
- `cocktail.*`: Cocktail data, persistence, filtering, and shopping-cart calculations.
- `secwindow.*` and `add_zutat.*`: Dialogs for creating cocktails and entering ingredients.
- `wk_window.*`: Shopping-list window.
- `Cocktail_2.pro`: qmake project file.
