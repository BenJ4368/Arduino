# 🔲 Arduino LED Matrix Display

Ce projet Arduino permet d'afficher du texte défilant sur une matrice LED 🟩.

## 🧰 Matériel utilisé
- 🧠 Microcontrôleur Arduino Uno
- 💡 Matrice LED 8x32
- 🔌 Câblage et alimentation adaptée

## 📦 Bibliothèques utilisées
- 📚 `Adafruit_GFX`
- 📚 `Adafruit_LEDBackpack`

## 🎨 Personnalisation

- ✏️ **Texte affiché** : modifiez la variable `message` dans le code.
- 🖌️ **Couleur du texte** : modifiez les valeurs RGB de la ligne 32 `matrix.setTextColor(matrix.Color(221, 110, 15));`.
- 🐢 **Vitesse de défilement** : ajustez le `scrollspeed` pour ralentir ou accélérer le texte.
- 📐 **Taille de la matrice** : adaptez les paramètres si vous utilisez une matrice différente.
- ⏳ **Durée d'affichage** : modifiez **executionDuration** et **pauseDuration**, respectivement le temps d'affichage, et le temps de pause de l'affichage.
