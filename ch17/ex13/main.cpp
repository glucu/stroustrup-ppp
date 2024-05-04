#include "Link.hpp"

int main()
{
    try {
       
        Link *gods{ new Link{Link::God{"Thor", "Norse", "Chariot", "Mjolnir"}} };
        gods = gods->insert(new Link{Link::God{"Freya", "Norse", "Cats", "None"}});
        gods = gods->insert(new Link{Link::God{"Odin", "Norse", "Sleipnir", "Gungnir"}});
        gods = gods->insert(new Link{Link::God{"Loki", "Norse", "Sleipnir", "Laevateinn"}});
        gods = gods->insert(new Link{Link::God{"Freyr", "Norse", "Gullinbursti", "Skíðblaðnir"}});
        gods = gods->insert(new Link{Link::God{"Frigg", "Norse", "Hliðskjálf", "Griðarvölr"}});
        gods = gods->insert(new Link{Link::God{"Tyr", "Norse", "Fenrir", "Dromi"}});
        gods = gods->insert(new Link{Link::God{"Baldr", "Norse", "Hringhorni", "Mistilteinn"}});

        gods = gods->insert(new Link{Link::God{"Zeus", "Greek", "Pegasus", "Thunderbolt"}});
        gods = gods->insert(new Link{Link::God{"Hera", "Greek", "Peacock", "Scepter"}});
        gods = gods->insert(new Link{Link::God{"Poseidon", "Greek", "Horse", "Trident"}});
        gods = gods->insert(new Link{Link::God{"Athena", "Greek", "Owl", "Spear"}});
        gods = gods->insert(new Link{Link::God{"Aphrodite", "Greek", "Dove", "Girdle"}});
        gods = gods->insert(new Link{Link::God{"Apollo", "Greek", "Lyre", "Bow"}});
        gods = gods->insert(new Link{Link::God{"Artemis", "Greek", "Deer", "Bow"}});

        gods = gods->insert(new Link{Link::God{"Ra", "Egyptian", "Sun disk", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Osiris", "Egyptian", "Crook and flail", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Isis", "Egyptian", "Throne", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Anubis", "Egyptian", "Jackal", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Horus", "Egyptian", "Falcon", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Thoth", "Egyptian", "Ibis", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Seth", "Egyptian", "Unknown", "Unknown"}});
        gods = gods->insert(new Link{Link::God{"Bastet", "Egyptian", "Cat", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Sobek", "Egyptian", "Crocodile", "Ankh"}});
        gods = gods->insert(new Link{Link::God{"Hathor", "Egyptian", "Cow", "Ankh"}});


        Link *norse{};
        Link *greeks{};
        Link *egyptians{};
        for(auto curr = gods; curr; curr = curr->next()) {
            auto tmp = new Link{curr->value};
            if(tmp->value.mythology == "Norse") {
                 norse = norse->add_ordered(tmp);
            }
            else if(tmp->value.mythology == "Greek") {
                greeks = greeks->add_ordered(tmp);
            }
            else if(tmp->value.mythology == "Egyptian") {
                egyptians = egyptians->add_ordered(tmp);
            }
        }

        cout << "NORSE GODS:\n";
        norse->print_all();

        cout << "\n\nGREEK GODS:\n";
        greeks->print_all();

        cout << "\n\nEGYPTIANS:\n";
        egyptians->print_all();

        return 0;
    }
    catch(exception &e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Oops: something went wrong\n";
        return 2;
    }
} 
