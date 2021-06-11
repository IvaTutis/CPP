#pragma once

#include <vector>
#include <list>
#include <ostream>
#include <optional>

// Rječnik na bazi hash tabele
template <typename Key, typename Value, typename Hash = std::hash<Key>>
class HashTable{
    private:

    //BUCKET CLASS-------------------------------------------------------------------------------------------------------------------------------------------------
    class Bucket{ 

    public:
        using BucketValue = std::pair<Key, Value>; 

    private:
        std::list<BucketValue> mData;

    public:
        
        //konstruktori_bucket-----------------------------
        //jedini bitan konstruktor je defaultan, koji inicijalizira mData kao praznu listu

        //funkcije_bucket-----------------------------

        //vraca #podataka u bucketu 
        size_t size(){ return mData.size();};

        //vraca vrijednost od kljuca, ako postoji --DONE
        std::optional<Value> get_by_key(Key key) {
            std::optional<Value> V;
           
            //check if pair with the given key exists, if so, set the optional value to the corresponding key=>value
            std::list<BucketValue>::iterator it;
            for (it=mData.begin(); it != mData.end() ; ++it){
                if (it->first == key) {
                    V = it->second;
                    break;
                }
            };
            
            return V;
        };

        //stavlja novu vrijednost na mjesto stare ako par s tim kljucem vec postoji, inace stvara novi i ubacuje ga u listu --DONE
        void add_or_update(Key key, Value value){ 

            //update value if pair with the given key exists
            std::list<BucketValue>::iterator it;
            for (it = mData.begin(); it != mData.end(); ++it){
                if (it->first == key){
                    it->second = value;
                    return;
                }
            };

            //otherwise, chuck in a new pair at the list front
            auto novi_element=std:make_pair(key, value); 
            mData.push_back(novi_element);
        };

        //mice iz liste par s danim kljucem --  DONE
        bool remove_by_key(Key key){
            bool exists = false;

            //remove if pair with the given key exists
            std::list<BucketValue>::iterator it;
            for (it = mData.begin(); it != mData.end(); ++it) {
                if (it->first == key) {
                    it = mylist.erase(it);
                    exists = true;
                }
            };

            return exists;
        };

        //printa elemente  -- DONE
        void print(std::ostream& out){

            std::list<BucketValue>::iterator it;
            for (it = mData.begin(); it != mData.end(); ++it) {

                out << it->second;
                if (it != mData.begin() && std::next(it) != mData.end())out << " , ";

            };    
        };

        // Nađi prvi element na koje predikat vraća "true". --DONE
        template <typename Predicat>
        std::optional<BucketValue> find_if(Predicat p) const {
            std::optional<BucketValue> B;

            std::list<BucketValue>::iterator it;
            for (it = mData.begin(); it != mData.end(); ++it) {
                if (p(*it)) {
                    return (std::optional<BucketValue>) * it;
                    break;
                }
            };

            return B;

        };

        // Vrati listu svih elemenata na kojima predikat vraća "true". --DONE
        template <typename Predicat>
        std::list<BucketValue> find_all_if(Predicat p) const {
            std::list<BucketValue> B_list;

            std::list<BucketValue>::iterator it;
            for (it = mData.begin(); it != mData.end(); ++it) {
                if (p(*it)) {
                    B_list.push_back(*it);
                }
            };

            return B_list;

        
        };
    };//------------------------------------------------------------------------------------------------------------------------------------------------

    using  BucketValue = typename Bucket::BucketValue;

    // Podaci = vektor s bucketima, hash funkcija mHasher 
    std::vector<Bucket> mBuckets;
    Hash mHasher;

    public:
        //----------------------------konstruktori_HashTable-----------------------------------------------

        //konstruktor po defaultu stvara 101 bucket, ili zadano, te je defaultna hash funkcija std::hash
        HashTable(size_t N = 101, Hash hasher = Hash()) : mBuckets(N), mHasher(hasher) { }

        //copy constructor ne postoji
        HashTable(HashTable const &) = delete;

        //AND operator ne postoji
        HashTable & operator=(HashTable const &) = delete;

        //---------------------------funkcije_HashTable----------------------------------

        // Broj elemenata u tabeli. ---DONE
        size_t size() const {
            size_t element_num = 0; 
            
            for (int i = 0; i < mBuckets.size(); i++) {
                element_num = element_num + mBuckets[i].size();
            }; 

            return element_num; 
        
        };

        //vraća #elemenata u mBuckets --DONE
        size_t bucket_number() const { return mBuckets.size(); }

        // Ispis čitave strukture (pretinci i povezane liste) radi kontrole. --DONE
        void print(std::ostream& out) {
            for (int i; i<this->bucket_number(); ++i){
                mBuckets[i].print(out);
                if (i != 0 && i + 1 != this->bucket_number) out << " , ";
            }
        
        };

        //  Vrati vrijednost koja odgovara ključu ---DONE
        std::optional<Value> value(Key key) {
            auto hash_value = mHasher(key);

            std::optional<Value> v = mBuckets[hash_value].get_by_key(key);

            return v; 
        };


        // Ukloni ključ ako je prisutan i vrati true ako je uklonjen i false inače. --DONE
        bool remove(Key key) {
            auto hash_value = mHasher(key);

            bool b = mBuckets[hash_value].remove_by_key(key);

            return b;
        };

        // Dodaj par "(key, value)" ako nije u spremniku.
        // U suprotnom ključu "key" daj vrijednost "value". --DONE
        void add_or_update(Key key, Value value) {
            auto hash_value = mHasher(key);

            mBuckets[hash_value].add_or_update(key, value);
        };

        // Nađi prvi element na koje predikat vraća "true".
        template <typename Predicat>
        std::optional<BucketValue> find_if(Predicat p) const {
            std::optional<BucketValue> B; 


            for (int i; i < this->bucket_number(); ++i) {
                B = mBuckets[i].find_if(p);
                if (B.has_value())break; 
            }

            return B;
        
        };

        // Vrati listu svih elemenata na kojima predikat vraća "true".
        template <typename Predicat>
        std::list<BucketValue> find_all_if(Predicat p) const {
            std::list<BucketValue> B_masterlist;


            for (int i; i < this->bucket_number(); ++i) {
                std::list<BucketValue> B_list = mBuckets[i].find_all_if(p);
                B_masterlist.merge(B_list);
            }

            return B_masterlist;
        };
};
