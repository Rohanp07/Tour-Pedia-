
import mongoose from 'mongoose';
import TourModel from '../models/tour.js';

export const createTour = async (req, res) => {

    console.log("user id is ", req.userId);

    
    const tour = req.body;
    const newTour = new TourModel({
        ...tour,
        creator: req.userId,
        createdAt: new Date().toISOString(),

    });

    try {
        await newTour.save();
        res.status(201).json(newTour);

    } catch (err) {
        console.log(err);
        res.status(404).json({ message: "something went wrong while creating tour" });
    }
}

export const getTours = async (req, res) => {
    const { page } = req.query;

    try {
        // const tour = await TourModel.findById(id);

        // res.status(200).json(tour);

        const limit = 6;
        const startIdx = (Number(page) - 1) * limit;
        const total = await TourModel.countDocuments();
        const tours = await TourModel.find().limit(limit).skip(startIdx);



        res.json({
            data: tours,
            currentPage: Number(page),
            totalTours: total,
            numberOfPages: Math.ceil(total / limit)
        })

    } catch (err) {
        res.status(404).json({ message: "something went wrong while getting tours" });
    }
}

export const getTour = async (req, res) => {
    const { id } = req.params;

    try {
        const tour = await TourModel.findById(id);

        res.status(200).json(tour);
    } catch (err) {
        res.status(404).json({ message: "something went wrong while getting tours" });
    }

}

//user  tours
export const getToursByUser = async (req, res) => {

    const { id } = req.params;
    // console.log("in getToursbyUser", id);

    if (!mongoose.Types.ObjectId.isValid(id)) {
        res.status(404).json({ message: "invalid user id" });
    }

    const userTours = await TourModel.find({ creator: id });
    res.status(200).json(userTours);


}

export const deleteTour = async (req, res) => {
    const { id } = req.params;



    try {
        if (!mongoose.Types.ObjectId.isValid(id)) {
            res.status(404).json({ message: `No tour exist with this id : ${id}` });

        }

        await TourModel.findByIdAndRemove(id);

        res.json({ message: "Tour deleted successfully" });
    } catch (err) {

        res.status(404).json({ message: "something went wrong while deleting tour" });


    }



}

export const updateTour = async (req, res) => {
    const { id } = req.params;
    const { title, description, creator, imageFile, tags } = req.body;

    try {
        if (!mongoose.Types.ObjectId.isValid(id)) {
            res.status(404).json({ message: `No tour exist with this id : ${id}` });

        }

        const updatedTour = {
            title,
            description,
            creator,
            imageFile,
            tags,
            _id: id,
        }
        //to update the tour
        await TourModel.findByIdAndUpdate(id, updatedTour, { new: true });

        res.json(updatedTour);

    } catch (err) {

        res.status(404).json({ message: "something went wrong while updating tour" });


    }



}

//search functionality 
export const getToursBySearch = async (req, res) => {

    const { searchQuery } = req.query;
    console.log("in controller  searchQuery  ", searchQuery);
    try {
        const title = new RegExp(searchQuery, 'i');
        const tours = await TourModel.find({ title });

        res.json(tours);

    } catch (err) {

        res.status(404).json({ message: "something went wrong while searching tours" });
    }
}

export const getToursByTag = async (req, res) => {

    const { tag } = req.params;
    try {
        const tours = await TourModel.find({ tags: { $in: tag } });
        res.json(tours);

    } catch (err) {

        res.status(404).json({ message: "something went wrong while searching tours by tag" });

    }
}


export const getRelatedTours = async (req, res) => {

    const tags = req.body;
    try {
        const tours = await TourModel.find({ tags: { $in: tags } });
        res.json(tours);

    } catch (err) {

        res.status(404).json({ message: "something went wrong while searching tours by tags" });

    }
}
