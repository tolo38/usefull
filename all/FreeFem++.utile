to use FreeFem++ create a .edp file
to see the help type : ?

mesh Sh= square(10,10); // mesh generation of a square
fespace Vh(Sh,P1); // space of P1 Finite Elements
Vh u,v; // u and v belongs to Vh
func f=cos(x)*y; // f is a function of x and y
problem Poisson(u,v)= // Definition of the problem
int2d(Sh)(dx(u)*dx(v)+dy(u)*dy(v)) // bilinear form
	-int2d(Sh)(f*v) // linear form
	+on(1,2,3,4,u=0); // Dirichlet Conditions
Poisson; // Solve Poisson Equation
plot(u); // Plot the result

About Meshes
• mesh = Type for... meshes;
• square = To create structured meshes;
• savemesh = To save a mesh in a file;
• readmesh = To read mesh previously saved;
• border = Type for parametrized curves;
• buildmesh = Build a mesh with parametrized boundaries;
• adaptmesh = To refine a mesh.
Attention les buildmesh doivent être construit dans l'ordre trigo
About Variational Formulations
• fespace = Type for Finite Element Spaces;
• problem =Type for a Variational Problem;
• P1,P2,P3 = Lagrange Elements;
• int2d = Integration over a domain;
• int1d = Integration over part of the boundary;
• on = To impose Boundary Conditions.
Misc...
• func = Type for a function of x and y;
• int = Type for integers;
• plot = Just guess;
• include = To include a script into another;
• ofstream = To direct the output to a file;
• ifstream = To get the input from a file.
• cos = All classical maths functions could be used;

