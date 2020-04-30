pour faire du profiling

option de compilation à ajouté : -pg

=> lors de l'éxecution ( ./main ) -> génération de "gmon.out"

on obtient le profiling avec :
gprof gmon.out
