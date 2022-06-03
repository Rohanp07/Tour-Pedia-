
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

    try {
        const tours = await TourModel.find();

        res.status(200).json(tours);
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
    console.log("in getToursbyUser",id);

    if (!mongoose.Types.ObjectId.isValid(id)) {
        res.status(404).json({ message: "invalid user id" });
    }

    const userTours = await TourModel.find({ creator: id });
    res.status(200).json(userTours);


}