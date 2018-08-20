//test site for struct

//declare the dictfile otherwise choose one for testing
    //char *dictfile = argv[1];

    typedef struct node
    {
        bool isword;
        struct node *children[27];
    }
    node;

    node *root = NULL;

    //open dictionary file
    FILE *dict_ptr = fopen(dictfile, "r");
    if (dict_ptr == NULL)
    {
        return false;
    }

    int wordcount = 0;

    for (char letter = fgetc(dict_ptr); letter != EOF; letter++)
    {
        node *current;
        current = malloc(sizeof(node));
        current = root;

        node *nextnode = malloc(sizeof(node));
        current->children[letter - "a"] = nextnode;

        if( letter == "\n")
        {
            nextnode->isword = true;
            current = root;
            wordcount++;
        }
    }
