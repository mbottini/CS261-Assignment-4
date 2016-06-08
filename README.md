# CS261-Assignment-4

Practices polymorphism by implementing an **Item** superclass and three subclasses: **Book**, **MusicAlbum**, and **Movie**. Each
object has a Title, an Originator (could be an Author, Band, or Director), some sort of Quantity, (pages, songs, scenes) and
Keywords. Two of the three have Collaborators (actors or band members). All of these need to be separately searchable, 
so Library.cpp implements a bunch of Sets and Maps to search according to said criteria.

std::shared_ptr is not allowed, so I rolled my own really rudimentary shared_ptr class for Item objects. It implements a
reference counter that counts how many times it's copied to some other container.

Asgmt04.cpp is explicitly provided by the professor, and I am not allowed to change a bit of it.

Output must match the provided asgmt04.output.txt, minus the whitespace because the professor was inconsistent as hell and
doesn't care. As a result, output must match `diff -w -B asgmt04.output.txt.`

All of the Visual Studio crap was provided by the professor as well, as I have to turn it in as a Visual Studio Project instead
of tarballing it like a normal person.

Varidic argument template is provided by the teacher. I've never used it before, but it seems to work okay.

Current questions still being asked:

* Is it right to have `getCollaborators` and `setCollaborators` in the superclass, even though **Book** doesn't implement them?
* Each `addItem` function in Library.cpp has some repetitive code while adding to the various maps. Can that be put into a function?
* Is it a good idea to just call `deleteMapContents` on every Map? Alternatively, can we add each Map to some sort of container, and then iterate through each vector? I don't know if I would want to do that, though.
