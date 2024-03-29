cmake_minimum_required(VERSION 3.17)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(test_lists main_tests/main.c base/cell/cell.c base/list/list.c base/list/getsamples.c)

add_executable(test_queuetab main_tests/main_qt.c base/cell/cell.c base/list/list.c queue/queuetab.c)
add_executable(test_stack main_tests/main_stack.c base/cell/cell.c base/list/list.c stack/stack.c)
add_executable(test_stacktab main_tests/main_stab.c base/cell/cell.c base/list/list.c stack/stacktab.c)
add_executable(test_queuelist main_tests/main_ql.c base/cell/cell.c base/list/list.c queue/queuelist.c)
add_executable(test_circlist main_tests/main_circlist.c circlist/circlist.c base/list/list.c base/cell/cell.c base/list/getsamples.c base/list/getsamples.h)

#add_executable(test_cards circlist/circlist.c base/cell/cell.c base/list/list.c apps/cards/cards.c apps/cards/maincard.c utils/timer/timer.c)

add_executable(test_node main_tests/test_node.c base/node/node.c)
add_executable(test_tree utils/timer/timer.c main_tests/main_tree.c bintree/bintree.c base/node/node.c utils/intpow/intpow.c bintree/disp/displaybintree.c bintree/getsampletrees.c)
add_executable(test_samples main_tests/main_samples.c base/cell/cell.c base/list/list.c base/list/getsamples.c main_tests/main_samples.c)
add_executable(test_exo_bin_tree_fill_l_r exercises/bintrees/fill_bin_tree_left_to_right.c bintree/bintree.c base/node/node.c main_tests/exos_bintree/main_exo_bintree_fill_l_r.c bintree/disp/displaybintree.c utils/intpow/intpow.c)
add_executable(test_exo_bin_tree_random exercises/bintrees/fill_bin_tree_random.c main_tests/exos_bintree/main_exo_bintree_fill_random.c bintree/bintree.c base/node/node.c bintree/disp/displaybintree.c)
add_executable(test_htlist main_tests/main_htlist.c base/list/list.c base/cell/cell.c base/list/getsamples.c)
add_executable(test_tree_visit main_tests/main_tree_visits.c bintree/bintree.c bintree/visits/breadth_first.c bintree/visits/rec_visit.c base/node/node.c exercises/bintrees/fill_bin_tree_left_to_right.c utils/intpow/intpow.c)
#add_executable(test_n_node main_tests/test_n_node.c base/n_node/n_node.c)
add_executable(test_char_trees main_tests/main_char_tree.c base/node/char_node/char_node.c bintree/char_bintree/char_bintree.c bintree/char_bintree/rec_visit.c)
add_executable(test_BST utils/timer/timer.c main_tests/main_BST.c bintree/bintree.c base/node/node.c utils/intpow/intpow.c bintree/disp/displaybintree.c bintree/getsampletrees.c)
