
# c#

### CL Arguments

Have default command line arguments if empty :
(Replace args string array)

```C#
using System;
using System.Collections.Generic;
using System.Windows.Forms;

static class Program {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main(string[] args) {
        if (args.Length == 0)
        {
            args = new string[]{"-param1","value","-p2","option"};
        }
        try {
        SingleApplication.Run(new Process(args));
        }
        catch(Exception excp) {
        System.Console.WriteLine(excp.ToString());
        }
    }
}
```
