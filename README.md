# Bunny Simulation
A project I made that simulates a population of bunnies. This project was done for a Scientific Computing course, written in C++. 

From project description:

At program initialization 10 bunnies (no mutants) must be created and given randomly chosen
characteristics of gender, color, and name.
- Each turn afterwards the bunnies age 1 year.
- For each male/female pair age 2-8 years: a new bunny is created each turn; genderX may pair
  with any other gender and has a 50% chance of creating a new bunny. Each bunny can pair at
  most once per turn.
- The color of new bunnies born should be randomly chosen between their mother and father;
  other characteristics (gender, name, and radioactive) are chosen randomly.
- If a bunny becomes older than 10 years old, it dies.
  
If a radioactive mutant vampire bunny is born then each turn it will change exactly one
  non-radioactive bunny into a radioactive vampire bunny. (If there are two radioactive mutant
  vampire bunnies two bunnies will be changed each turn and so on...)
- Radioactive vampire bunnies are excluded from regular breeding and do not count as adult
  bunnies.
- Radioactive vampire bunnies do not die until they reach age 50.

Original Project Description created by Dr. Leslie Kerby, CS Department, Idaho State University