// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: test_libxml.c

// this file is used to test the libxml features before
// incorporating into the main capstone project

// attributions
// http://www.xmlsoft.org

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>


int main()
    {
    printf("testing libxml\n");
   
    xmlDoc* document;
    xmlNode* root;
    xmlNode* first_child;
    xmlNode* node;
    //char* filename = "sampleXML.txt";
    char* filename = "sampleXML2.txt";

    document = xmlReadFile(filename, NULL, 0);
    root = xmlDocGetRootElement(document);
    fprintf(stdout, "Root is <%s> (%i)\n", 
            root->name, root->type);
    first_child = root->children;
    for (node = first_child; node; node = node->next)
        {
        fprintf(stdout, "\t Child is <%s> (%i)\n",
                node->name, node->type);
        }
    fprintf(stdout, "...\n");

    return 0;
    }

