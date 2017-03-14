#Compiler sans tenir compte des accents
javac -encoding ISO-8859-1 *.java

#Compiler lorsque les sources sont distante
javac -classpath *.jar *.java  +Main.java

#et creer les .class dans le repertoir bin
javac  -d ./bin/ -cp ./src/ ./src/Test.java

#compiler la doc
javadoc -d doc ./src/*.java


#creer un .jar
jar cvmf ./META-INF/MANIFEST.MF Puissance4.jar /bin/*.class

#executer une class distante
java -cp ./bin Test

#voir la doc
firefox ./doc/index.html

#executer une archive .jar
java -jar *.jar
