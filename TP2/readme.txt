# 2 classes ont été créées : PageRank et TransitionMatrix

# TransitionMatrix :
- contient les infos sur le graph (pas vraiment la matrice de transition car trop lourd)
- edges : un set qui contient tous les edges
- id_nodes : dicto id node : indice
- id_nodes_inverse : dico indice : id node
- degrees : dico id node : degree node
- predecessors : dico id node : noeuds tels qu'il existe un edge ayant pour target le node

# PageRank :
- implementation de l'algo 
- page_rank_vec : vecteur du page rank
- pour faire la multiplication matrice de transtion x vecteur (fonction matMul) : iteration sur les elements du vecteurs, puis iteration sur les noeuds " predecesseurs ". *

# Pour faire tourner le code
- choisir un nbr d'itérations (dans le main.cpp)
- mettre les deux fichiers dans le dossier graph
- g++ main.cpp PageRank.cpp TransitionMatrix.cpp -o ../bin/test
- ../bin/test

