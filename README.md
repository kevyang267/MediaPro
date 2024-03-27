
# Media Pro
This application is going to be a desktop music player similar to Windows Media Player, but targeted towards those who wish to do more library organization then is posable within playlist systems. Instead of playlist, a tags and rules system will be used.

## Tags & Rules
This system involves classes of tags that are assigned to songs by the user. These tags can have additional attributes, for example an expiration date/timer where the tag will automatically be removed from a song after a period of time. If the default set of tags do not meet the needs of the user they can create there own classes of tags, and set and customize it's attributes.

The user selects a set of rules that are used to select what songs are put into the song que. These rules use tags and simple logic operations to determine what songs can be added and what order to add them in. Rules can be grouped together to make rule-sets that can be activated and deactivated. There are two basic types of rules, domain rules and order rules. Domain rules select what songs can be selected. Order rules select what order the songs from the domain are added into the que.

## Tags
Tags allow the user to add there own costume attributes to songs which can be used by the rules to control what is added to the que, or used in other functionality like searching.

#### Attributes
- Name (UNIQUE): A string that identifies the tag
- Colour: A hexadecimal value that determines the colour the tag will display with.
- Class: A id that identifies what tag class this tag belongs too.

### Tag Classes
**TODO** *(for now we can sick with just a basic tag and maybe a expiration timer one if we have time)*

## Rules
Rules allow the user to control what songs get added to the que, and the order they are added. Rules use song attributes and simple logic statement. There are two types of rules, Domain and Order.

### Domain Rules
Domain rules are responsible for selecting what songs can be added to the que. Each rule contains one or more lines of conditions, and each line is connected together with AND's or OR's. Each line in a Domain rule is made up by a type of song attribute, a condition, and a attribute value. For example `Artist == Beatles` or `Song Length < 4:00`. Multiple rules can be active at one time, by default, all rules must be satisfied (AND), but a rule can be marked as a exception rule (an OR instead of AND).

#### Available Conditions: 
Each condition is only available to some of the types of song attributes, so for example greater then is not available for Artist.
- `==`
- `>`
- `>=`
- `<`
- `<=`
- `!=`

### Order Rules
Order rules are responsible for selecting songs from the domain and adding them to the que in a specific order. There are two types of Order rules, Sort and Random. Sort rules are applied first, then any sets with matching attributes from the sort then has the Random rule applied, if one is active. There can only be one of each for Sort and Random rules. 

#### Sort Rules
Sort rules consist of an ordered list of attributes, where each attribute has an associated acceding or descending value. Whenever a Sort rule is active each song from the domain can only be selected once *(because you can't sort and infinite list)*. 

#### Random Rules
Random rules can be true random where each song in the domain always has an equal chance of being selected, or a weighted random. Weighted random allows for songs with selected attributes to have there weight increased or decreased, and can use attributes from earlier songs in the que to reduce repetition.

### Rule-Sets
Rule-Sets are used to group together rules so they can be easily activated and deactivated together. Rule-Sets have a user defined unique name associated with them so the user can identify them and there purpose. Each rule can be associated with multiple Rule-Sets.
